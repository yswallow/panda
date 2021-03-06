
#include "i2c_master.h"
#include "wait.h"
#include "matrix.h"
#include <print.h>
#include "quantum.h"
#include "panda.h"
#ifdef DEBUG_MATRIX_SCAN_RATE
    #include "timer.h"
#endif
uint8_t slave_address[MATRIX_ROWS] = MATRIX_SLAVE_ADDRESS;
uint8_t available_address[MATRIX_ROWS];

/* matrix state(1:on, 0:off) */
matrix_row_t matrix[MATRIX_ROWS];
matrix_row_t matrix_debouncing[MATRIX_ROWS];

//#define DEBOUNCE 5
uint8_t debouncing = DEBOUNCING_DELAY;

bool device_unavailable_caution = true;

#ifdef DEBUG_MATRIX_SCAN_RATE
uint32_t matrix_timer;
uint32_t matrix_scan_count;
#endif

void matrix_init(void) {
    //bool device_available = false;
    i2c_init();
    for(short i=0; i<MATRIX_ROWS; i++) {
        /*
        if( 0 == i2c_start(slave_address[i], MATRIX_INIT_TIMEOUT) ) {
            available_address[i] = slave_address[i];
            //デフォルトで入力 (IODIR is set(1) )
            
            buffer[0] = 0x0C; //PULLUP
            buffer[1] = 0xFF;
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            buffer[0] = 0x0D;
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            buffer[0] = 0x02; //IPOL 論理反転
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            buffer[0] = 0x03;
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            
            //device_available = true;
            i2c_stop();
        } else {
            available_address[i] = 0x00;
        }
        */
        if( (available_address[i] = panda_matrix_init(slave_address[i])) ) {
            device_unavailable_caution = false;
        }
    }
    
    /*if(! device_available) {
        SEND_STRING("I2C slave device not found.");
    }*/
    #ifdef DEBUG_MATRIX_SCAN_RATE
        matrix_timer = timer_read32();
        matrix_scan_count = 0;
    #endif
    
    matrix_init_quantum();
}

uint8_t scan_count;
uint8_t matrix_scan(void) {
    uint8_t buffer[2] = {0x00, 0x00};
    
    #ifdef DEBUG_MATRIX_SCAN_RATE
        matrix_scan_count++;

        uint32_t timer_now = timer_read32();
        if (TIMER_DIFF_32(timer_now, matrix_timer)>1000) {
            print("matrix scan frequency: ");
            pdec(matrix_scan_count);
            print("\n");
            matrix_print();

            matrix_timer = timer_now;
            matrix_scan_count = 0;
        }
    #endif

    scan_count--;
    for(uint8_t i=0; i<MATRIX_ROWS; i++) {
        if(available_address[i]) {
            i2c_status_t result = 0;
            wait_us(30);
            //matrix_row_t cols = read_cols(i);
            buffer[0] = 0x12;
            result |= i2c_start(slave_address[i], MATRIX_SCAN_TIMEOUT);
            result |= i2c_transmit(slave_address[i], buffer, 1, MATRIX_SCAN_TIMEOUT); 
            result |= i2c_receive(slave_address[i], buffer, 2, MATRIX_SCAN_TIMEOUT);
            i2c_stop();
            if(result) {
                buffer[0] = buffer[1] = 0x00;
            }
            matrix_row_t cols =  buffer[1] << 8 | buffer[0];
            //end read_cols(i)

            if(matrix_debouncing[i] != cols) {
                matrix_debouncing[i] = cols;
                debouncing = DEBOUNCING_DELAY;
            }

            //matrix[i] = buffer[1] << 8 | buffer[0];
        } else {
            if(! scan_count) {
                if( (available_address[i] = panda_matrix_init(slave_address[i])) ) {
                    #ifdef PANDA_LED_ENABLE
                        #ifdef NUMLOCK_LED_ADDRESS
                            if(NUMLOCK_LED_ADDRESS == available_address[i])
                                panda_led_init(NUMLOCK_LED_ADDRESS, NUMLOCK_LED_PORT, NUMLOCK_LED_PIN_NUMBER);
                        #endif
                        #ifdef CAPSLOCK_LED_ADDRESS
                            if(CAPSLOCK_LED_ADDRESS == available_address[i])
                                panda_led_init(CAPSLOCK_LED_ADDRESS, CAPSLOCK_LED_PORT, CAPSLOCK_LED_PIN_NUMBER);
                        #endif
                        #ifdef SCROLLLOCK_LED_ADDRESS
                            if(SCROLLLOCK_LED_ADDRESS == available_address[i])
                                panda_led_init(SCROLLLOCK_LED_ADDRESS, SCROLLLOCK_LED_PORT, SCROLLLOCK_LED_PIN_NUMBER);
                        #endif
                    #endif
                }
            }
            //matrix[i] = 0x0000;
            matrix_debouncing[i] = 0x0000;
        }
    }
    /*
    if(device_unavailable_caution) {
        wait_ms(1000); 
        SEND_STRING("I2C slave device not found.\t");
        device_unavailable_caution = false;
    }
    */
    if(debouncing) {
        if(--debouncing) {
            wait_ms(1);
        } else {
            for(uint8_t i=0; i<MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }
    matrix_scan_quantum();
    
    return 1;
}

matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_print(void)
{

}

