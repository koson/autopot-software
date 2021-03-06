/**************************************************************************
 *
 *                  FTDIChip AN_275 FT800 with Arduino - Version 1.0
 *
 **************************************************************************
 * FileName:        FT800.h
 * Purpose:         This header file contains the display list and graphics
 *                  processor commands for the FTDI FT800 graphics controller chip
 * Dependencies:    See INCLUDES section below
 * Processor:       Atmel Atmega328 @ 16MHz
 * IDE:             Arduino v1.0.5 or later
 * Company:         Future Technology Devices International Ltd.
 *
 * Software License Agreement
 *
 * Software License Agreement
 *
 * This code is provided as an example only and is not guaranteed by FTDI.
 * FTDI accept no responsibility for any issues resulting from its use.
 * The developer of the final application incorporating any parts of this
 * sample project is responsible for ensuring its safe and correct operation
 * and for any conequences resulting from its use.
 *
 * Author	Date		Rev		Comment
 **************************************************************************
 * BR		2013-11-01	1.0		Initial version
 **************************************************************************

*/

#ifndef FT800_h
#define FT800_h

/*****************************************************************************/
/************************* I N C L U D E S ***********************************/
/*****************************************************************************/
//#include <Arduino.h>

/*****************************************************************************/
/********************** D E C L A R A T I O N S ******************************/
/*****************************************************************************/

#define FT_DL_SIZE            (8*1024)  //8KB Display List buffer size
#define FT_CMD_FIFO_SIZE      (4*1024)  //4KB coprocessor Fifo size
#define FT_CMD_SIZE           (4)       //4 byte per coprocessor command of EVE

#define FT800_VERSION         "1.9.0"

// Refer to the FT800 Datasheet

// FT800 Memory Map Addresses
#define RAM_CMD               0x108000UL
#define RAM_DL                0x100000UL
#define RAM_G                 0x000000UL
#define RAM_PAL               0x102000UL
#define RAM_REG               0x102400UL

// FT800 Register Addresses
#define REG_CLOCK             0x102408UL
#define REG_CMD_DL            0x1024ecUL
#define REG_CMD_READ          0x1024e4UL
#define REG_CMD_WRITE         0x1024e8UL
#define REG_CPURESET          0x10241cUL
#define REG_CSPREAD           0x102464UL
#define REG_DITHER            0x10245cUL
#define REG_DLSWAP            0x102450UL
#define REG_FRAMES            0x102404UL
#define REG_FREQUENCY         0x10240cUL
#define REG_GPIO              0x102490UL
#define REG_GPIO_DIR          0x10248cUL
#define REG_HCYCLE            0x102428UL
#define REG_HOFFSET           0x10242cUL
#define REG_HSIZE             0x102430UL
#define REG_HSYNC0            0x102434UL
#define REG_HSYNC1            0x102438UL
#define REG_ID                0x102400UL
#define REG_INT_EN            0x10249cUL
#define REG_INT_FLAGS         0x102498UL
#define REG_INT_MASK          0x1024a0UL
#define REG_MACRO_0           0x1024c8UL
#define REG_MACRO_1           0x1024ccUL
#define REG_OUTBITS           0x102458UL
#define REG_PCLK              0x10246cUL
#define REG_PCLK_POL          0x102468UL
#define REG_PLAY              0x102488UL
#define REG_PLAYBACK_FORMAT   0x1024b4UL
#define REG_PLAYBACK_FREQ     0x1024b0UL
#define REG_PLAYBACK_LENGTH   0x1024a8UL
#define REG_PLAYBACK_LOOP     0x1024b8UL
#define REG_PLAYBACK_PLAY     0x1024bcUL
#define REG_PLAYBACK_READPTR  0x1024acUL
#define REG_PLAYBACK_START    0x1024a4UL
#define REG_PWM_DUTY          0x1024c4UL
#define REG_PWM_HZ            0x1024c0UL
#define REG_RENDERMODE        0x102410UL
#define REG_ROTATE            0x102454UL
#define REG_SNAPSHOT          0x102418UL
#define REG_SNAPY             0x102414UL
#define REG_SOUND             0x102484UL
#define REG_SWIZZLE           0x102460UL
#define REG_TAG               0x102478UL
#define REG_TAG_X             0x102470UL
#define REG_TAG_Y             0x102474UL
#define REG_TAP_CRC           0x102420UL
#define REG_TAP_MASK          0x102424UL
#define REG_TOUCH_ADC_MODE    0x1024f4UL
#define REG_TOUCH_CHARGE      0x1024f8UL
#define REG_TOUCH_DIRECT_XY   0x102574UL
#define REG_TOUCH_DIRECT_Z1Z2 0x102578UL
#define REG_TOUCH_MODE        0x1024f0UL
#define REG_TOUCH_OVERSAMPLE  0x102500UL
#define REG_TOUCH_RAW_XY      0x102508UL
#define REG_TOUCH_RZ          0x10250cUL
#define REG_TOUCH_RZTHRESH    0x102504UL
#define REG_TOUCH_SCREEN_XY   0x102510UL
#define REG_TOUCH_SETTLE      0x1024fcUL
#define REG_TOUCH_TAG         0x102518UL
#define REG_TOUCH_TAG_XY      0x102514UL
#define REG_TOUCH_TRANSFORM_A 0x10251cUL
#define REG_TOUCH_TRANSFORM_B 0x102520UL
#define REG_TOUCH_TRANSFORM_C 0x102524UL
#define REG_TOUCH_TRANSFORM_D 0x102528UL
#define REG_TOUCH_TRANSFORM_E 0x10252cUL
#define REG_TOUCH_TRANSFORM_F 0x102530UL
#define REG_TRACKER           0x109000UL
#define REG_VCYCLE            0x10243cUL
#define REG_VOFFSET           0x102440UL
#define REG_VOL_PB            0x10247cUL
#define REG_VOL_SOUND         0x102480UL
#define REG_VSIZE             0x102444UL
#define REG_VSYNC0            0x102448UL
#define REG_VSYNC1            0x10244cUL

// Graphics Engine Commands
// Refer to the FT800 Programmers Guide
#define CMDBUF_SIZE          4096UL
#define CMD_APPEND           0xffffff1eUL
#define CMD_BGCOLOR          0xffffff09UL
#define CMD_BUTTON           0xffffff0dUL
#define CMD_CALIBRATE        0xffffff15UL
#define CMD_CLOCK            0xffffff14UL
#define CMD_COLDSTART        0xffffff32UL
#define CMD_DIAL             0xffffff2dUL
#define CMD_DLSTART          0xffffff00UL
#define CMD_FGCOLOR          0xffffff0aUL
#define CMD_GAUGE            0xffffff13UL
#define CMD_GETMATRIX        0xffffff33UL
#define CMD_GETPTR           0xffffff23UL
#define CMD_GRADCOLOR        0xffffff34UL
#define CMD_GRADIENT         0xffffff0bUL
#define CMD_INFLATE          0xffffff22UL
#define CMD_INTERRUPT        0xffffff02UL
#define CMD_KEYS             0xffffff0eUL
#define CMD_LOADIDENTITY     0xffffff26UL
#define CMD_LOADIMAGE        0xffffff24UL
#define CMD_LOGO             0xffffff31UL
#define CMD_MEMCPY           0xffffff1dUL
#define CMD_MEMCRC           0xffffff18UL
#define CMD_MEMSET           0xffffff1bUL
#define CMD_MEMWRITE         0xffffff1aUL
#define CMD_MEMZERO          0xffffff1cUL
#define CMD_NUMBER           0xffffff2eUL
#define CMD_PROGRESS         0xffffff0fUL
#define CMD_REGREAD          0xffffff19UL
#define CMD_ROTATE           0xffffff29UL
#define CMD_SCALE            0xffffff28UL
#define CMD_SCREENSAVER      0xffffff2fUL
#define CMD_SCROLLBAR        0xffffff11UL
#define CMD_SETFONT          0xffffff2bUL
#define CMD_SETMATRIX        0xffffff2aUL
#define CMD_SKETCH           0xffffff30UL
#define CMD_SLIDER           0xffffff10UL
#define CMD_SNAPSHOT         0xffffff1fUL
#define CMD_SPINNER          0xffffff16UL
#define CMD_STOP             0xffffff17UL
#define CMD_SWAP             0xffffff01UL
#define CMD_TEXT             0xffffff0cUL
#define CMD_TOGGLE           0xffffff12UL
#define CMD_TRACK            0xffffff2cUL
#define CMD_TRANSLATE        0xffffff27UL

// Display list commands to be embedded in Graphics Processor
#define DL_ALPHA_FUNC       0x09000000UL // requires OR'd arguments
#define DL_BITMAP_HANDLE    0x05000000UL // requires OR'd arguments
#define DL_BITMAP_LAYOUT    0x07000000UL // requires OR'd arguments
#define DL_BITMAP_SIZE      0x08000000UL // requires OR'd arguments
#define DL_BITMAP_SOURCE    0x01000000UL // requires OR'd arguments
#define DL_BITMAP_TFORM_A   0x15000000UL // requires OR'd arguments
#define DL_BITMAP_TFORM_B   0x16000000UL // requires OR'd arguments
#define DL_BITMAP_TFORM_C   0x17000000UL // requires OR'd arguments
#define DL_BITMAP_TFORM_D   0x18000000UL // requires OR'd arguments
#define DL_BITMAP_TFORM_E   0x19000000UL // requires OR'd arguments
#define DL_BITMAP_TFORM_F   0x1A000000UL // requires OR'd arguments
#define DL_BLEND_FUNC       0x0B000000UL // requires OR'd arguments
#define DL_BEGIN            0x1F000000UL // requires OR'd arguments
#define DL_CALL             0x1D000000UL // requires OR'd arguments
#define DL_CLEAR            0x26000000UL // requires OR'd arguments
#define DL_CELL             0x06000000UL // requires OR'd arguments
#define DL_CLEAR_RGB        0x02000000UL // requires OR'd arguments
#define DL_CLEAR_STENCIL    0x11000000UL // requires OR'd arguments
#define DL_CLEAR_TAG        0x12000000UL // requires OR'd arguments
#define DL_COLOR_A          0x0F000000UL // requires OR'd arguments
#define DL_COLOR_MASK       0x20000000UL // requires OR'd arguments
#define DL_COLOR_RGB        0x04000000UL // requires OR'd arguments
#define DL_DISPLAY          0x00000000UL
#define DL_END              0x21000000UL
#define DL_JUMP             0x1E000000UL // requires OR'd arguments
#define DL_LINE_WIDTH       0x0E000000UL // requires OR'd arguments
#define DL_MACRO            0x25000000UL // requires OR'd arguments
#define DL_POINT_SIZE       0x0D000000UL // requires OR'd arguments
#define DL_RESTORE_CONTEXT  0x23000000UL
#define DL_RETURN           0x24000000UL
#define DL_SAVE_CONTEXT     0x22000000UL
#define DL_SCISSOR_SIZE     0x1C000000UL // requires OR'd arguments
#define DL_SCISSOR_XY       0x1B000000UL // requires OR'd arguments
#define DL_STENCIL_FUNC     0x0A000000UL // requires OR'd arguments
#define DL_STENCIL_MASK     0x13000000UL // requires OR'd arguments
#define DL_STENCIL_OP       0x0C000000UL // requires OR'd arguments
#define DL_TAG              0x03000000UL // requires OR'd arguments
#define DL_TAG_MASK         0x14000000UL // requires OR'd arguments
#define DL_VERTEX2F         0x40000000UL // requires OR'd arguments
#define DL_VERTEX2II        0x02000000UL // requires OR'd arguments

// Command and register value options
#define CLR_COL              0x4
#define CLR_STN              0x2
#define CLR_TAG              0x1
#define DECR                 4UL
#define DECR_WRAP            7UL
#define DLSWAP_DONE          0UL
#define DLSWAP_FRAME         2UL
#define DLSWAP_LINE          1UL
#define DST_ALPHA            3UL
#define EDGE_STRIP_A         7UL
#define EDGE_STRIP_B         8UL
#define EDGE_STRIP_L         6UL
#define EDGE_STRIP_R         5UL
#define EQUAL                5UL
#define GEQUAL               4UL
#define GREATER              3UL
#define INCR                 3UL
#define INCR_WRAP            6UL
#define INT_CMDEMPTY         32UL
#define INT_CMDFLAG          64UL
#define INT_CONVCOMPLETE     128UL
#define INT_PLAYBACK         16UL
#define INT_SOUND            8UL
#define INT_SWAP             1UL
#define INT_TAG              4UL
#define INT_TOUCH            2UL
#define INVERT               5UL
#define KEEP                 1UL
#define L1                   1UL
#define L4                   2UL
#define L8                   3UL
#define LEQUAL               2UL
#define LESS                 1UL
#define LINEAR_SAMPLES       0UL
#define LINES                3UL
#define LINE_STRIP           4UL
#define NEAREST              0UL
#define NEVER                0UL
#define NOTEQUAL             6UL
#define ONE                  1UL
#define ONE_MINUS_DST_ALPHA  5UL
#define ONE_MINUS_SRC_ALPHA  4UL
#define OPT_CENTER           1536UL    // 0x6000
#define OPT_CENTERX          512UL     // 0x0200
#define OPT_CENTERY          1024UL    // 0x0400
#define OPT_FLAT             256UL     // 0x0100
#define OPT_MONO             1UL
#define OPT_NOBACK           4096UL    // 0x1000
#define OPT_NODL             2UL
#define OPT_NOHANDS          49152UL   // 0xC168
#define OPT_NOHM             16384UL   // 0x4000
#define OPT_NOPOINTER        16384UL   // 0x4000
#define OPT_NOSECS           32768UL   // 0x8000
#define OPT_NOTICKS          8192UL    // 0x2000
#define OPT_RIGHTX           2048UL    // 0x0800
#define OPT_SIGNED           256UL     // 0x0100
#define PALETTED             8UL
#define PLAYCOLOR            0x00a0a080
#define FTPOINTS             2UL       // "POINTS" is a reserved word
#define RECTS                9UL
#define REPEAT               1UL
#define REPLACE              2UL
#define RGB332               4UL
#define RGB565               7UL
#define SRC_ALPHA            2UL
#define TEXT8X8              9UL
#define TEXTVGA              10UL
#define TOUCHMODE_CONTINUOUS 3UL
#define TOUCHMODE_FRAME      2UL
#define TOUCHMODE_OFF        0UL
#define TOUCHMODE_ONESHOT    1UL
#define ULAW_SAMPLES         1UL
#define ZERO                 0UL

// Useful Macros
#define RGB(r, g, b)         ((((r) << 16) | (g) << 8) | (b))
#define SQ(v)                ((v) * (v))
#define MIN(x,y)             ((x) > (y) ? (y) : (x))
#define MAX(x,y)             ((x) > (y) ? (x) : (y))
#define NOTE(n, sharp)       (((n) - 'C') + ((sharp) * 128))
#define F16(s)               (((s) * 65536))
#define INVALID_TOUCH_XY     0x8000
#define ABS(x)               ((x) > (0) ? (x) : (-x))


class   FT800
{
    //OneWire oneWire;
    //bool    present;
    //bool    model_s;
    //uint8_t data[12];
    //uint8_t addr[8];
    //float   toFloat(uint16_t word);
  public:

    //DS1820(PinName pin);
    //DS1820(char model, PinName pin);
    //bool   begin(void);
    //bool   isPresent();
    //void   setResolution(uint8_t res);
    //void   startConversion(void);
    //float  read(void);
    FT800();
    unsigned int triggerPin;			// Used for oscilloscope/logic analyzer trigger
    unsigned int ft800irqPin;			// Interrupt from FT800 to Arduino - not used here
    unsigned int ft800pwrPin;			// PD_N from Arduino to FT800 - effectively FT800 reset
    unsigned int ft800csPin;			// SPI chip select - defined separately since it's manipulated with GPIO calls
    void ft800memWrite8(unsigned long ftAddress, unsigned char ftData8);
    void ft800memWrite16(unsigned long ftAddress, unsigned int ftData16);
    void ft800memWrite32(unsigned long ftAddress, unsigned long ftData32);
    unsigned char ft800memRead8(unsigned long ftAddress);
    unsigned int ft800memRead16(unsigned long ftAddress);
    unsigned long ft800memRead32(unsigned long ftAddress);
    void ft800cmdWrite(unsigned char ftCommand);
    unsigned int incCMDOffset(unsigned int currentOffset, unsigned char commandSize);
    unsigned int displayText(FT800 ft800, unsigned long ftAddress, const char* text, unsigned int initX, unsigned int initY, unsigned int cmdOffset);
    void init(FT800 ft800);
    void draw(FT800 ft800, unsigned int cmdOffset, unsigned int COLOR, double celsius, unsigned int plant_temp_min, unsigned int plant_temp_max);
    void black(FT800 ft800);
};
#endif  //FT800_h
/** EOF FT800.h ********************************************************/
