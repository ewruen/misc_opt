#include "simd_type.h"

/* ---------------------------- */
/* --- alpha standard table --- */
/* ---------------------------- */
ALIGN(16) 
unsigned long apt_standard[4096] = 
{
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x01000100, 0x00000100, 0x01000100, 0x00000100,
0x02000200, 0x00000200, 0x02000200, 0x00000200,
0x03000300, 0x00000300, 0x03000300, 0x00000300,
0x04000400, 0x00000400, 0x04000400, 0x00000400,
0x05000500, 0x00000500, 0x05000500, 0x00000500,
0x06000600, 0x00000600, 0x06000600, 0x00000600,
0x07000700, 0x00000700, 0x07000700, 0x00000700,
0x08000800, 0x00000800, 0x08000800, 0x00000800,
0x09000900, 0x00000900, 0x09000900, 0x00000900,
0x0A000A00, 0x00000A00, 0x0A000A00, 0x00000A00,
0x0B000B00, 0x00000B00, 0x0B000B00, 0x00000B00,
0x0C000C00, 0x00000C00, 0x0C000C00, 0x00000C00,
0x0D000D00, 0x00000D00, 0x0D000D00, 0x00000D00,
0x0E000E00, 0x00000E00, 0x0E000E00, 0x00000E00,
0x0F000F00, 0x00000F00, 0x0F000F00, 0x00000F00,
0x10001000, 0x00001000, 0x10001000, 0x00001000,
0x11001100, 0x00001100, 0x11001100, 0x00001100,
0x12001200, 0x00001200, 0x12001200, 0x00001200,
0x13001300, 0x00001300, 0x13001300, 0x00001300,
0x14001400, 0x00001400, 0x14001400, 0x00001400,
0x15001500, 0x00001500, 0x15001500, 0x00001500,
0x16001600, 0x00001600, 0x16001600, 0x00001600,
0x17001700, 0x00001700, 0x17001700, 0x00001700,
0x18001800, 0x00001800, 0x18001800, 0x00001800,
0x19001900, 0x00001900, 0x19001900, 0x00001900,
0x1A001A00, 0x00001A00, 0x1A001A00, 0x00001A00,
0x1B001B00, 0x00001B00, 0x1B001B00, 0x00001B00,
0x1C001C00, 0x00001C00, 0x1C001C00, 0x00001C00,
0x1D001D00, 0x00001D00, 0x1D001D00, 0x00001D00,
0x1E001E00, 0x00001E00, 0x1E001E00, 0x00001E00,
0x1F001F00, 0x00001F00, 0x1F001F00, 0x00001F00,
0x20002000, 0x00002000, 0x20002000, 0x00002000,
0x21002100, 0x00002100, 0x21002100, 0x00002100,
0x22002200, 0x00002200, 0x22002200, 0x00002200,
0x23002300, 0x00002300, 0x23002300, 0x00002300,
0x24002400, 0x00002400, 0x24002400, 0x00002400,
0x25002500, 0x00002500, 0x25002500, 0x00002500,
0x26002600, 0x00002600, 0x26002600, 0x00002600,
0x27002700, 0x00002700, 0x27002700, 0x00002700,
0x28002800, 0x00002800, 0x28002800, 0x00002800,
0x29002900, 0x00002900, 0x29002900, 0x00002900,
0x2A002A00, 0x00002A00, 0x2A002A00, 0x00002A00,
0x2B002B00, 0x00002B00, 0x2B002B00, 0x00002B00,
0x2C002C00, 0x00002C00, 0x2C002C00, 0x00002C00,
0x2D002D00, 0x00002D00, 0x2D002D00, 0x00002D00,
0x2E002E00, 0x00002E00, 0x2E002E00, 0x00002E00,
0x2F002F00, 0x00002F00, 0x2F002F00, 0x00002F00,
0x30003000, 0x00003000, 0x30003000, 0x00003000,
0x31003100, 0x00003100, 0x31003100, 0x00003100,
0x32003200, 0x00003200, 0x32003200, 0x00003200,
0x33003300, 0x00003300, 0x33003300, 0x00003300,
0x34003400, 0x00003400, 0x34003400, 0x00003400,
0x35003500, 0x00003500, 0x35003500, 0x00003500,
0x36003600, 0x00003600, 0x36003600, 0x00003600,
0x37003700, 0x00003700, 0x37003700, 0x00003700,
0x38003800, 0x00003800, 0x38003800, 0x00003800,
0x39003900, 0x00003900, 0x39003900, 0x00003900,
0x3A003A00, 0x00003A00, 0x3A003A00, 0x00003A00,
0x3B003B00, 0x00003B00, 0x3B003B00, 0x00003B00,
0x3C003C00, 0x00003C00, 0x3C003C00, 0x00003C00,
0x3D003D00, 0x00003D00, 0x3D003D00, 0x00003D00,
0x3E003E00, 0x00003E00, 0x3E003E00, 0x00003E00,
0x3F003F00, 0x00003F00, 0x3F003F00, 0x00003F00,
0x40004000, 0x00004000, 0x40004000, 0x00004000,
0x41004100, 0x00004100, 0x41004100, 0x00004100,
0x42004200, 0x00004200, 0x42004200, 0x00004200,
0x43004300, 0x00004300, 0x43004300, 0x00004300,
0x44004400, 0x00004400, 0x44004400, 0x00004400,
0x45004500, 0x00004500, 0x45004500, 0x00004500,
0x46004600, 0x00004600, 0x46004600, 0x00004600,
0x47004700, 0x00004700, 0x47004700, 0x00004700,
0x48004800, 0x00004800, 0x48004800, 0x00004800,
0x49004900, 0x00004900, 0x49004900, 0x00004900,
0x4A004A00, 0x00004A00, 0x4A004A00, 0x00004A00,
0x4B004B00, 0x00004B00, 0x4B004B00, 0x00004B00,
0x4C004C00, 0x00004C00, 0x4C004C00, 0x00004C00,
0x4D004D00, 0x00004D00, 0x4D004D00, 0x00004D00,
0x4E004E00, 0x00004E00, 0x4E004E00, 0x00004E00,
0x4F004F00, 0x00004F00, 0x4F004F00, 0x00004F00,
0x50005000, 0x00005000, 0x50005000, 0x00005000,
0x51005100, 0x00005100, 0x51005100, 0x00005100,
0x52005200, 0x00005200, 0x52005200, 0x00005200,
0x53005300, 0x00005300, 0x53005300, 0x00005300,
0x54005400, 0x00005400, 0x54005400, 0x00005400,
0x55005500, 0x00005500, 0x55005500, 0x00005500,
0x56005600, 0x00005600, 0x56005600, 0x00005600,
0x57005700, 0x00005700, 0x57005700, 0x00005700,
0x58005800, 0x00005800, 0x58005800, 0x00005800,
0x59005900, 0x00005900, 0x59005900, 0x00005900,
0x5A005A00, 0x00005A00, 0x5A005A00, 0x00005A00,
0x5B005B00, 0x00005B00, 0x5B005B00, 0x00005B00,
0x5C005C00, 0x00005C00, 0x5C005C00, 0x00005C00,
0x5D005D00, 0x00005D00, 0x5D005D00, 0x00005D00,
0x5E005E00, 0x00005E00, 0x5E005E00, 0x00005E00,
0x5F005F00, 0x00005F00, 0x5F005F00, 0x00005F00,
0x60006000, 0x00006000, 0x60006000, 0x00006000,
0x61006100, 0x00006100, 0x61006100, 0x00006100,
0x62006200, 0x00006200, 0x62006200, 0x00006200,
0x63006300, 0x00006300, 0x63006300, 0x00006300,
0x64006400, 0x00006400, 0x64006400, 0x00006400,
0x65006500, 0x00006500, 0x65006500, 0x00006500,
0x66006600, 0x00006600, 0x66006600, 0x00006600,
0x67006700, 0x00006700, 0x67006700, 0x00006700,
0x68006800, 0x00006800, 0x68006800, 0x00006800,
0x69006900, 0x00006900, 0x69006900, 0x00006900,
0x6A006A00, 0x00006A00, 0x6A006A00, 0x00006A00,
0x6B006B00, 0x00006B00, 0x6B006B00, 0x00006B00,
0x6C006C00, 0x00006C00, 0x6C006C00, 0x00006C00,
0x6D006D00, 0x00006D00, 0x6D006D00, 0x00006D00,
0x6E006E00, 0x00006E00, 0x6E006E00, 0x00006E00,
0x6F006F00, 0x00006F00, 0x6F006F00, 0x00006F00,
0x70007000, 0x00007000, 0x70007000, 0x00007000,
0x71007100, 0x00007100, 0x71007100, 0x00007100,
0x72007200, 0x00007200, 0x72007200, 0x00007200,
0x73007300, 0x00007300, 0x73007300, 0x00007300,
0x74007400, 0x00007400, 0x74007400, 0x00007400,
0x75007500, 0x00007500, 0x75007500, 0x00007500,
0x76007600, 0x00007600, 0x76007600, 0x00007600,
0x77007700, 0x00007700, 0x77007700, 0x00007700,
0x78007800, 0x00007800, 0x78007800, 0x00007800,
0x79007900, 0x00007900, 0x79007900, 0x00007900,
0x7A007A00, 0x00007A00, 0x7A007A00, 0x00007A00,
0x7B007B00, 0x00007B00, 0x7B007B00, 0x00007B00,
0x7C007C00, 0x00007C00, 0x7C007C00, 0x00007C00,
0x7D007D00, 0x00007D00, 0x7D007D00, 0x00007D00,
0x7E007E00, 0x00007E00, 0x7E007E00, 0x00007E00,
0x7F007F00, 0x00007F00, 0x7F007F00, 0x00007F00,
0x80008000, 0x00008000, 0x80008000, 0x00008000,
0x81008100, 0x00008100, 0x81008100, 0x00008100,
0x82008200, 0x00008200, 0x82008200, 0x00008200,
0x83008300, 0x00008300, 0x83008300, 0x00008300,
0x84008400, 0x00008400, 0x84008400, 0x00008400,
0x85008500, 0x00008500, 0x85008500, 0x00008500,
0x86008600, 0x00008600, 0x86008600, 0x00008600,
0x87008700, 0x00008700, 0x87008700, 0x00008700,
0x88008800, 0x00008800, 0x88008800, 0x00008800,
0x89008900, 0x00008900, 0x89008900, 0x00008900,
0x8A008A00, 0x00008A00, 0x8A008A00, 0x00008A00,
0x8B008B00, 0x00008B00, 0x8B008B00, 0x00008B00,
0x8C008C00, 0x00008C00, 0x8C008C00, 0x00008C00,
0x8D008D00, 0x00008D00, 0x8D008D00, 0x00008D00,
0x8E008E00, 0x00008E00, 0x8E008E00, 0x00008E00,
0x8F008F00, 0x00008F00, 0x8F008F00, 0x00008F00,
0x90009000, 0x00009000, 0x90009000, 0x00009000,
0x91009100, 0x00009100, 0x91009100, 0x00009100,
0x92009200, 0x00009200, 0x92009200, 0x00009200,
0x93009300, 0x00009300, 0x93009300, 0x00009300,
0x94009400, 0x00009400, 0x94009400, 0x00009400,
0x95009500, 0x00009500, 0x95009500, 0x00009500,
0x96009600, 0x00009600, 0x96009600, 0x00009600,
0x97009700, 0x00009700, 0x97009700, 0x00009700,
0x98009800, 0x00009800, 0x98009800, 0x00009800,
0x99009900, 0x00009900, 0x99009900, 0x00009900,
0x9A009A00, 0x00009A00, 0x9A009A00, 0x00009A00,
0x9B009B00, 0x00009B00, 0x9B009B00, 0x00009B00,
0x9C009C00, 0x00009C00, 0x9C009C00, 0x00009C00,
0x9D009D00, 0x00009D00, 0x9D009D00, 0x00009D00,
0x9E009E00, 0x00009E00, 0x9E009E00, 0x00009E00,
0x9F009F00, 0x00009F00, 0x9F009F00, 0x00009F00,
0xA000A000, 0x0000A000, 0xA000A000, 0x0000A000,
0xA100A100, 0x0000A100, 0xA100A100, 0x0000A100,
0xA200A200, 0x0000A200, 0xA200A200, 0x0000A200,
0xA300A300, 0x0000A300, 0xA300A300, 0x0000A300,
0xA400A400, 0x0000A400, 0xA400A400, 0x0000A400,
0xA500A500, 0x0000A500, 0xA500A500, 0x0000A500,
0xA600A600, 0x0000A600, 0xA600A600, 0x0000A600,
0xA700A700, 0x0000A700, 0xA700A700, 0x0000A700,
0xA800A800, 0x0000A800, 0xA800A800, 0x0000A800,
0xA900A900, 0x0000A900, 0xA900A900, 0x0000A900,
0xAA00AA00, 0x0000AA00, 0xAA00AA00, 0x0000AA00,
0xAB00AB00, 0x0000AB00, 0xAB00AB00, 0x0000AB00,
0xAC00AC00, 0x0000AC00, 0xAC00AC00, 0x0000AC00,
0xAD00AD00, 0x0000AD00, 0xAD00AD00, 0x0000AD00,
0xAE00AE00, 0x0000AE00, 0xAE00AE00, 0x0000AE00,
0xAF00AF00, 0x0000AF00, 0xAF00AF00, 0x0000AF00,
0xB000B000, 0x0000B000, 0xB000B000, 0x0000B000,
0xB100B100, 0x0000B100, 0xB100B100, 0x0000B100,
0xB200B200, 0x0000B200, 0xB200B200, 0x0000B200,
0xB300B300, 0x0000B300, 0xB300B300, 0x0000B300,
0xB400B400, 0x0000B400, 0xB400B400, 0x0000B400,
0xB500B500, 0x0000B500, 0xB500B500, 0x0000B500,
0xB600B600, 0x0000B600, 0xB600B600, 0x0000B600,
0xB700B700, 0x0000B700, 0xB700B700, 0x0000B700,
0xB800B800, 0x0000B800, 0xB800B800, 0x0000B800,
0xB900B900, 0x0000B900, 0xB900B900, 0x0000B900,
0xBA00BA00, 0x0000BA00, 0xBA00BA00, 0x0000BA00,
0xBB00BB00, 0x0000BB00, 0xBB00BB00, 0x0000BB00,
0xBC00BC00, 0x0000BC00, 0xBC00BC00, 0x0000BC00,
0xBD00BD00, 0x0000BD00, 0xBD00BD00, 0x0000BD00,
0xBE00BE00, 0x0000BE00, 0xBE00BE00, 0x0000BE00,
0xBF00BF00, 0x0000BF00, 0xBF00BF00, 0x0000BF00,
0xC000C000, 0x0000C000, 0xC000C000, 0x0000C000,
0xC100C100, 0x0000C100, 0xC100C100, 0x0000C100,
0xC200C200, 0x0000C200, 0xC200C200, 0x0000C200,
0xC300C300, 0x0000C300, 0xC300C300, 0x0000C300,
0xC400C400, 0x0000C400, 0xC400C400, 0x0000C400,
0xC500C500, 0x0000C500, 0xC500C500, 0x0000C500,
0xC600C600, 0x0000C600, 0xC600C600, 0x0000C600,
0xC700C700, 0x0000C700, 0xC700C700, 0x0000C700,
0xC800C800, 0x0000C800, 0xC800C800, 0x0000C800,
0xC900C900, 0x0000C900, 0xC900C900, 0x0000C900,
0xCA00CA00, 0x0000CA00, 0xCA00CA00, 0x0000CA00,
0xCB00CB00, 0x0000CB00, 0xCB00CB00, 0x0000CB00,
0xCC00CC00, 0x0000CC00, 0xCC00CC00, 0x0000CC00,
0xCD00CD00, 0x0000CD00, 0xCD00CD00, 0x0000CD00,
0xCE00CE00, 0x0000CE00, 0xCE00CE00, 0x0000CE00,
0xCF00CF00, 0x0000CF00, 0xCF00CF00, 0x0000CF00,
0xD000D000, 0x0000D000, 0xD000D000, 0x0000D000,
0xD100D100, 0x0000D100, 0xD100D100, 0x0000D100,
0xD200D200, 0x0000D200, 0xD200D200, 0x0000D200,
0xD300D300, 0x0000D300, 0xD300D300, 0x0000D300,
0xD400D400, 0x0000D400, 0xD400D400, 0x0000D400,
0xD500D500, 0x0000D500, 0xD500D500, 0x0000D500,
0xD600D600, 0x0000D600, 0xD600D600, 0x0000D600,
0xD700D700, 0x0000D700, 0xD700D700, 0x0000D700,
0xD800D800, 0x0000D800, 0xD800D800, 0x0000D800,
0xD900D900, 0x0000D900, 0xD900D900, 0x0000D900,
0xDA00DA00, 0x0000DA00, 0xDA00DA00, 0x0000DA00,
0xDB00DB00, 0x0000DB00, 0xDB00DB00, 0x0000DB00,
0xDC00DC00, 0x0000DC00, 0xDC00DC00, 0x0000DC00,
0xDD00DD00, 0x0000DD00, 0xDD00DD00, 0x0000DD00,
0xDE00DE00, 0x0000DE00, 0xDE00DE00, 0x0000DE00,
0xDF00DF00, 0x0000DF00, 0xDF00DF00, 0x0000DF00,
0xE000E000, 0x0000E000, 0xE000E000, 0x0000E000,
0xE100E100, 0x0000E100, 0xE100E100, 0x0000E100,
0xE200E200, 0x0000E200, 0xE200E200, 0x0000E200,
0xE300E300, 0x0000E300, 0xE300E300, 0x0000E300,
0xE400E400, 0x0000E400, 0xE400E400, 0x0000E400,
0xE500E500, 0x0000E500, 0xE500E500, 0x0000E500,
0xE600E600, 0x0000E600, 0xE600E600, 0x0000E600,
0xE700E700, 0x0000E700, 0xE700E700, 0x0000E700,
0xE800E800, 0x0000E800, 0xE800E800, 0x0000E800,
0xE900E900, 0x0000E900, 0xE900E900, 0x0000E900,
0xEA00EA00, 0x0000EA00, 0xEA00EA00, 0x0000EA00,
0xEB00EB00, 0x0000EB00, 0xEB00EB00, 0x0000EB00,
0xEC00EC00, 0x0000EC00, 0xEC00EC00, 0x0000EC00,
0xED00ED00, 0x0000ED00, 0xED00ED00, 0x0000ED00,
0xEE00EE00, 0x0000EE00, 0xEE00EE00, 0x0000EE00,
0xEF00EF00, 0x0000EF00, 0xEF00EF00, 0x0000EF00,
0xF000F000, 0x0000F000, 0xF000F000, 0x0000F000,
0xF100F100, 0x0000F100, 0xF100F100, 0x0000F100,
0xF200F200, 0x0000F200, 0xF200F200, 0x0000F200,
0xF300F300, 0x0000F300, 0xF300F300, 0x0000F300,
0xF400F400, 0x0000F400, 0xF400F400, 0x0000F400,
0xF500F500, 0x0000F500, 0xF500F500, 0x0000F500,
0xF600F600, 0x0000F600, 0xF600F600, 0x0000F600,
0xF700F700, 0x0000F700, 0xF700F700, 0x0000F700,
0xF800F800, 0x0000F800, 0xF800F800, 0x0000F800,
0xF900F900, 0x0000F900, 0xF900F900, 0x0000F900,
0xFA00FA00, 0x0000FA00, 0xFA00FA00, 0x0000FA00,
0xFB00FB00, 0x0000FB00, 0xFB00FB00, 0x0000FB00,
0xFC00FC00, 0x0000FC00, 0xFC00FC00, 0x0000FC00,
0xFD00FD00, 0x0000FD00, 0xFD00FD00, 0x0000FD00,
0xFE00FE00, 0x0000FE00, 0xFE00FE00, 0x0000FE00,
0xFF00FF00, 0x0000FF00, 0xFF00FF00, 0x0000FF00
};
/* -------------------------------- */
/* --- alpha standard table rev --- */
/* -------------------------------- */
ALIGN(16) 
unsigned long apt_standard_r[4096] = 
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xFF00FF00, 0x0000FF00, 0xFF00FF00, 0x0000FF00,
0xFE00FE00, 0x0000FE00, 0xFE00FE00, 0x0000FE00,
0xFD00FD00, 0x0000FD00, 0xFD00FD00, 0x0000FD00,
0xFC00FC00, 0x0000FC00, 0xFC00FC00, 0x0000FC00,
0xFB00FB00, 0x0000FB00, 0xFB00FB00, 0x0000FB00,
0xFA00FA00, 0x0000FA00, 0xFA00FA00, 0x0000FA00,
0xF900F900, 0x0000F900, 0xF900F900, 0x0000F900,
0xF800F800, 0x0000F800, 0xF800F800, 0x0000F800,
0xF700F700, 0x0000F700, 0xF700F700, 0x0000F700,
0xF600F600, 0x0000F600, 0xF600F600, 0x0000F600,
0xF500F500, 0x0000F500, 0xF500F500, 0x0000F500,
0xF400F400, 0x0000F400, 0xF400F400, 0x0000F400,
0xF300F300, 0x0000F300, 0xF300F300, 0x0000F300,
0xF200F200, 0x0000F200, 0xF200F200, 0x0000F200,
0xF100F100, 0x0000F100, 0xF100F100, 0x0000F100,
0xF000F000, 0x0000F000, 0xF000F000, 0x0000F000,
0xEF00EF00, 0x0000EF00, 0xEF00EF00, 0x0000EF00,
0xEE00EE00, 0x0000EE00, 0xEE00EE00, 0x0000EE00,
0xED00ED00, 0x0000ED00, 0xED00ED00, 0x0000ED00,
0xEC00EC00, 0x0000EC00, 0xEC00EC00, 0x0000EC00,
0xEB00EB00, 0x0000EB00, 0xEB00EB00, 0x0000EB00,
0xEA00EA00, 0x0000EA00, 0xEA00EA00, 0x0000EA00,
0xE900E900, 0x0000E900, 0xE900E900, 0x0000E900,
0xE800E800, 0x0000E800, 0xE800E800, 0x0000E800,
0xE700E700, 0x0000E700, 0xE700E700, 0x0000E700,
0xE600E600, 0x0000E600, 0xE600E600, 0x0000E600,
0xE500E500, 0x0000E500, 0xE500E500, 0x0000E500,
0xE400E400, 0x0000E400, 0xE400E400, 0x0000E400,
0xE300E300, 0x0000E300, 0xE300E300, 0x0000E300,
0xE200E200, 0x0000E200, 0xE200E200, 0x0000E200,
0xE100E100, 0x0000E100, 0xE100E100, 0x0000E100,
0xE000E000, 0x0000E000, 0xE000E000, 0x0000E000,
0xDF00DF00, 0x0000DF00, 0xDF00DF00, 0x0000DF00,
0xDE00DE00, 0x0000DE00, 0xDE00DE00, 0x0000DE00,
0xDD00DD00, 0x0000DD00, 0xDD00DD00, 0x0000DD00,
0xDC00DC00, 0x0000DC00, 0xDC00DC00, 0x0000DC00,
0xDB00DB00, 0x0000DB00, 0xDB00DB00, 0x0000DB00,
0xDA00DA00, 0x0000DA00, 0xDA00DA00, 0x0000DA00,
0xD900D900, 0x0000D900, 0xD900D900, 0x0000D900,
0xD800D800, 0x0000D800, 0xD800D800, 0x0000D800,
0xD700D700, 0x0000D700, 0xD700D700, 0x0000D700,
0xD600D600, 0x0000D600, 0xD600D600, 0x0000D600,
0xD500D500, 0x0000D500, 0xD500D500, 0x0000D500,
0xD400D400, 0x0000D400, 0xD400D400, 0x0000D400,
0xD300D300, 0x0000D300, 0xD300D300, 0x0000D300,
0xD200D200, 0x0000D200, 0xD200D200, 0x0000D200,
0xD100D100, 0x0000D100, 0xD100D100, 0x0000D100,
0xD000D000, 0x0000D000, 0xD000D000, 0x0000D000,
0xCF00CF00, 0x0000CF00, 0xCF00CF00, 0x0000CF00,
0xCE00CE00, 0x0000CE00, 0xCE00CE00, 0x0000CE00,
0xCD00CD00, 0x0000CD00, 0xCD00CD00, 0x0000CD00,
0xCC00CC00, 0x0000CC00, 0xCC00CC00, 0x0000CC00,
0xCB00CB00, 0x0000CB00, 0xCB00CB00, 0x0000CB00,
0xCA00CA00, 0x0000CA00, 0xCA00CA00, 0x0000CA00,
0xC900C900, 0x0000C900, 0xC900C900, 0x0000C900,
0xC800C800, 0x0000C800, 0xC800C800, 0x0000C800,
0xC700C700, 0x0000C700, 0xC700C700, 0x0000C700,
0xC600C600, 0x0000C600, 0xC600C600, 0x0000C600,
0xC500C500, 0x0000C500, 0xC500C500, 0x0000C500,
0xC400C400, 0x0000C400, 0xC400C400, 0x0000C400,
0xC300C300, 0x0000C300, 0xC300C300, 0x0000C300,
0xC200C200, 0x0000C200, 0xC200C200, 0x0000C200,
0xC100C100, 0x0000C100, 0xC100C100, 0x0000C100,
0xC000C000, 0x0000C000, 0xC000C000, 0x0000C000,
0xBF00BF00, 0x0000BF00, 0xBF00BF00, 0x0000BF00,
0xBE00BE00, 0x0000BE00, 0xBE00BE00, 0x0000BE00,
0xBD00BD00, 0x0000BD00, 0xBD00BD00, 0x0000BD00,
0xBC00BC00, 0x0000BC00, 0xBC00BC00, 0x0000BC00,
0xBB00BB00, 0x0000BB00, 0xBB00BB00, 0x0000BB00,
0xBA00BA00, 0x0000BA00, 0xBA00BA00, 0x0000BA00,
0xB900B900, 0x0000B900, 0xB900B900, 0x0000B900,
0xB800B800, 0x0000B800, 0xB800B800, 0x0000B800,
0xB700B700, 0x0000B700, 0xB700B700, 0x0000B700,
0xB600B600, 0x0000B600, 0xB600B600, 0x0000B600,
0xB500B500, 0x0000B500, 0xB500B500, 0x0000B500,
0xB400B400, 0x0000B400, 0xB400B400, 0x0000B400,
0xB300B300, 0x0000B300, 0xB300B300, 0x0000B300,
0xB200B200, 0x0000B200, 0xB200B200, 0x0000B200,
0xB100B100, 0x0000B100, 0xB100B100, 0x0000B100,
0xB000B000, 0x0000B000, 0xB000B000, 0x0000B000,
0xAF00AF00, 0x0000AF00, 0xAF00AF00, 0x0000AF00,
0xAE00AE00, 0x0000AE00, 0xAE00AE00, 0x0000AE00,
0xAD00AD00, 0x0000AD00, 0xAD00AD00, 0x0000AD00,
0xAC00AC00, 0x0000AC00, 0xAC00AC00, 0x0000AC00,
0xAB00AB00, 0x0000AB00, 0xAB00AB00, 0x0000AB00,
0xAA00AA00, 0x0000AA00, 0xAA00AA00, 0x0000AA00,
0xA900A900, 0x0000A900, 0xA900A900, 0x0000A900,
0xA800A800, 0x0000A800, 0xA800A800, 0x0000A800,
0xA700A700, 0x0000A700, 0xA700A700, 0x0000A700,
0xA600A600, 0x0000A600, 0xA600A600, 0x0000A600,
0xA500A500, 0x0000A500, 0xA500A500, 0x0000A500,
0xA400A400, 0x0000A400, 0xA400A400, 0x0000A400,
0xA300A300, 0x0000A300, 0xA300A300, 0x0000A300,
0xA200A200, 0x0000A200, 0xA200A200, 0x0000A200,
0xA100A100, 0x0000A100, 0xA100A100, 0x0000A100,
0xA000A000, 0x0000A000, 0xA000A000, 0x0000A000,
0x9F009F00, 0x00009F00, 0x9F009F00, 0x00009F00,
0x9E009E00, 0x00009E00, 0x9E009E00, 0x00009E00,
0x9D009D00, 0x00009D00, 0x9D009D00, 0x00009D00,
0x9C009C00, 0x00009C00, 0x9C009C00, 0x00009C00,
0x9B009B00, 0x00009B00, 0x9B009B00, 0x00009B00,
0x9A009A00, 0x00009A00, 0x9A009A00, 0x00009A00,
0x99009900, 0x00009900, 0x99009900, 0x00009900,
0x98009800, 0x00009800, 0x98009800, 0x00009800,
0x97009700, 0x00009700, 0x97009700, 0x00009700,
0x96009600, 0x00009600, 0x96009600, 0x00009600,
0x95009500, 0x00009500, 0x95009500, 0x00009500,
0x94009400, 0x00009400, 0x94009400, 0x00009400,
0x93009300, 0x00009300, 0x93009300, 0x00009300,
0x92009200, 0x00009200, 0x92009200, 0x00009200,
0x91009100, 0x00009100, 0x91009100, 0x00009100,
0x90009000, 0x00009000, 0x90009000, 0x00009000,
0x8F008F00, 0x00008F00, 0x8F008F00, 0x00008F00,
0x8E008E00, 0x00008E00, 0x8E008E00, 0x00008E00,
0x8D008D00, 0x00008D00, 0x8D008D00, 0x00008D00,
0x8C008C00, 0x00008C00, 0x8C008C00, 0x00008C00,
0x8B008B00, 0x00008B00, 0x8B008B00, 0x00008B00,
0x8A008A00, 0x00008A00, 0x8A008A00, 0x00008A00,
0x89008900, 0x00008900, 0x89008900, 0x00008900,
0x88008800, 0x00008800, 0x88008800, 0x00008800,
0x87008700, 0x00008700, 0x87008700, 0x00008700,
0x86008600, 0x00008600, 0x86008600, 0x00008600,
0x85008500, 0x00008500, 0x85008500, 0x00008500,
0x84008400, 0x00008400, 0x84008400, 0x00008400,
0x83008300, 0x00008300, 0x83008300, 0x00008300,
0x82008200, 0x00008200, 0x82008200, 0x00008200,
0x81008100, 0x00008100, 0x81008100, 0x00008100,
0x80008000, 0x00008000, 0x80008000, 0x00008000,
0x7F007F00, 0x00007F00, 0x7F007F00, 0x00007F00,
0x7E007E00, 0x00007E00, 0x7E007E00, 0x00007E00,
0x7D007D00, 0x00007D00, 0x7D007D00, 0x00007D00,
0x7C007C00, 0x00007C00, 0x7C007C00, 0x00007C00,
0x7B007B00, 0x00007B00, 0x7B007B00, 0x00007B00,
0x7A007A00, 0x00007A00, 0x7A007A00, 0x00007A00,
0x79007900, 0x00007900, 0x79007900, 0x00007900,
0x78007800, 0x00007800, 0x78007800, 0x00007800,
0x77007700, 0x00007700, 0x77007700, 0x00007700,
0x76007600, 0x00007600, 0x76007600, 0x00007600,
0x75007500, 0x00007500, 0x75007500, 0x00007500,
0x74007400, 0x00007400, 0x74007400, 0x00007400,
0x73007300, 0x00007300, 0x73007300, 0x00007300,
0x72007200, 0x00007200, 0x72007200, 0x00007200,
0x71007100, 0x00007100, 0x71007100, 0x00007100,
0x70007000, 0x00007000, 0x70007000, 0x00007000,
0x6F006F00, 0x00006F00, 0x6F006F00, 0x00006F00,
0x6E006E00, 0x00006E00, 0x6E006E00, 0x00006E00,
0x6D006D00, 0x00006D00, 0x6D006D00, 0x00006D00,
0x6C006C00, 0x00006C00, 0x6C006C00, 0x00006C00,
0x6B006B00, 0x00006B00, 0x6B006B00, 0x00006B00,
0x6A006A00, 0x00006A00, 0x6A006A00, 0x00006A00,
0x69006900, 0x00006900, 0x69006900, 0x00006900,
0x68006800, 0x00006800, 0x68006800, 0x00006800,
0x67006700, 0x00006700, 0x67006700, 0x00006700,
0x66006600, 0x00006600, 0x66006600, 0x00006600,
0x65006500, 0x00006500, 0x65006500, 0x00006500,
0x64006400, 0x00006400, 0x64006400, 0x00006400,
0x63006300, 0x00006300, 0x63006300, 0x00006300,
0x62006200, 0x00006200, 0x62006200, 0x00006200,
0x61006100, 0x00006100, 0x61006100, 0x00006100,
0x60006000, 0x00006000, 0x60006000, 0x00006000,
0x5F005F00, 0x00005F00, 0x5F005F00, 0x00005F00,
0x5E005E00, 0x00005E00, 0x5E005E00, 0x00005E00,
0x5D005D00, 0x00005D00, 0x5D005D00, 0x00005D00,
0x5C005C00, 0x00005C00, 0x5C005C00, 0x00005C00,
0x5B005B00, 0x00005B00, 0x5B005B00, 0x00005B00,
0x5A005A00, 0x00005A00, 0x5A005A00, 0x00005A00,
0x59005900, 0x00005900, 0x59005900, 0x00005900,
0x58005800, 0x00005800, 0x58005800, 0x00005800,
0x57005700, 0x00005700, 0x57005700, 0x00005700,
0x56005600, 0x00005600, 0x56005600, 0x00005600,
0x55005500, 0x00005500, 0x55005500, 0x00005500,
0x54005400, 0x00005400, 0x54005400, 0x00005400,
0x53005300, 0x00005300, 0x53005300, 0x00005300,
0x52005200, 0x00005200, 0x52005200, 0x00005200,
0x51005100, 0x00005100, 0x51005100, 0x00005100,
0x50005000, 0x00005000, 0x50005000, 0x00005000,
0x4F004F00, 0x00004F00, 0x4F004F00, 0x00004F00,
0x4E004E00, 0x00004E00, 0x4E004E00, 0x00004E00,
0x4D004D00, 0x00004D00, 0x4D004D00, 0x00004D00,
0x4C004C00, 0x00004C00, 0x4C004C00, 0x00004C00,
0x4B004B00, 0x00004B00, 0x4B004B00, 0x00004B00,
0x4A004A00, 0x00004A00, 0x4A004A00, 0x00004A00,
0x49004900, 0x00004900, 0x49004900, 0x00004900,
0x48004800, 0x00004800, 0x48004800, 0x00004800,
0x47004700, 0x00004700, 0x47004700, 0x00004700,
0x46004600, 0x00004600, 0x46004600, 0x00004600,
0x45004500, 0x00004500, 0x45004500, 0x00004500,
0x44004400, 0x00004400, 0x44004400, 0x00004400,
0x43004300, 0x00004300, 0x43004300, 0x00004300,
0x42004200, 0x00004200, 0x42004200, 0x00004200,
0x41004100, 0x00004100, 0x41004100, 0x00004100,
0x40004000, 0x00004000, 0x40004000, 0x00004000,
0x3F003F00, 0x00003F00, 0x3F003F00, 0x00003F00,
0x3E003E00, 0x00003E00, 0x3E003E00, 0x00003E00,
0x3D003D00, 0x00003D00, 0x3D003D00, 0x00003D00,
0x3C003C00, 0x00003C00, 0x3C003C00, 0x00003C00,
0x3B003B00, 0x00003B00, 0x3B003B00, 0x00003B00,
0x3A003A00, 0x00003A00, 0x3A003A00, 0x00003A00,
0x39003900, 0x00003900, 0x39003900, 0x00003900,
0x38003800, 0x00003800, 0x38003800, 0x00003800,
0x37003700, 0x00003700, 0x37003700, 0x00003700,
0x36003600, 0x00003600, 0x36003600, 0x00003600,
0x35003500, 0x00003500, 0x35003500, 0x00003500,
0x34003400, 0x00003400, 0x34003400, 0x00003400,
0x33003300, 0x00003300, 0x33003300, 0x00003300,
0x32003200, 0x00003200, 0x32003200, 0x00003200,
0x31003100, 0x00003100, 0x31003100, 0x00003100,
0x30003000, 0x00003000, 0x30003000, 0x00003000,
0x2F002F00, 0x00002F00, 0x2F002F00, 0x00002F00,
0x2E002E00, 0x00002E00, 0x2E002E00, 0x00002E00,
0x2D002D00, 0x00002D00, 0x2D002D00, 0x00002D00,
0x2C002C00, 0x00002C00, 0x2C002C00, 0x00002C00,
0x2B002B00, 0x00002B00, 0x2B002B00, 0x00002B00,
0x2A002A00, 0x00002A00, 0x2A002A00, 0x00002A00,
0x29002900, 0x00002900, 0x29002900, 0x00002900,
0x28002800, 0x00002800, 0x28002800, 0x00002800,
0x27002700, 0x00002700, 0x27002700, 0x00002700,
0x26002600, 0x00002600, 0x26002600, 0x00002600,
0x25002500, 0x00002500, 0x25002500, 0x00002500,
0x24002400, 0x00002400, 0x24002400, 0x00002400,
0x23002300, 0x00002300, 0x23002300, 0x00002300,
0x22002200, 0x00002200, 0x22002200, 0x00002200,
0x21002100, 0x00002100, 0x21002100, 0x00002100,
0x20002000, 0x00002000, 0x20002000, 0x00002000,
0x1F001F00, 0x00001F00, 0x1F001F00, 0x00001F00,
0x1E001E00, 0x00001E00, 0x1E001E00, 0x00001E00,
0x1D001D00, 0x00001D00, 0x1D001D00, 0x00001D00,
0x1C001C00, 0x00001C00, 0x1C001C00, 0x00001C00,
0x1B001B00, 0x00001B00, 0x1B001B00, 0x00001B00,
0x1A001A00, 0x00001A00, 0x1A001A00, 0x00001A00,
0x19001900, 0x00001900, 0x19001900, 0x00001900,
0x18001800, 0x00001800, 0x18001800, 0x00001800,
0x17001700, 0x00001700, 0x17001700, 0x00001700,
0x16001600, 0x00001600, 0x16001600, 0x00001600,
0x15001500, 0x00001500, 0x15001500, 0x00001500,
0x14001400, 0x00001400, 0x14001400, 0x00001400,
0x13001300, 0x00001300, 0x13001300, 0x00001300,
0x12001200, 0x00001200, 0x12001200, 0x00001200,
0x11001100, 0x00001100, 0x11001100, 0x00001100,
0x10001000, 0x00001000, 0x10001000, 0x00001000,
0x0F000F00, 0x00000F00, 0x0F000F00, 0x00000F00,
0x0E000E00, 0x00000E00, 0x0E000E00, 0x00000E00,
0x0D000D00, 0x00000D00, 0x0D000D00, 0x00000D00,
0x0C000C00, 0x00000C00, 0x0C000C00, 0x00000C00,
0x0B000B00, 0x00000B00, 0x0B000B00, 0x00000B00,
0x0A000A00, 0x00000A00, 0x0A000A00, 0x00000A00,
0x09000900, 0x00000900, 0x09000900, 0x00000900,
0x08000800, 0x00000800, 0x08000800, 0x00000800,
0x07000700, 0x00000700, 0x07000700, 0x00000700,
0x06000600, 0x00000600, 0x06000600, 0x00000600,
0x05000500, 0x00000500, 0x05000500, 0x00000500,
0x04000400, 0x00000400, 0x04000400, 0x00000400,
0x03000300, 0x00000300, 0x03000300, 0x00000300,
0x02000200, 0x00000200, 0x02000200, 0x00000200,
0x01000100, 0x00000100, 0x01000100, 0x00000100
};
/* ----------------------------- */
/* ----- alpha cross table ----- */
/* ----------------------------- */
ALIGN(16) 
unsigned long apt_cross[4096] = 
{
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x01FF01FF, 0x000001FF, 0x01FF01FF, 0x000001FF,
0x02FE02FE, 0x000002FE, 0x02FE02FE, 0x000002FE,
0x03FD03FD, 0x000003FD, 0x03FD03FD, 0x000003FD,
0x04FC04FC, 0x000004FC, 0x04FC04FC, 0x000004FC,
0x05FB05FB, 0x000005FB, 0x05FB05FB, 0x000005FB,
0x06FA06FA, 0x000006FA, 0x06FA06FA, 0x000006FA,
0x07F907F9, 0x000007F9, 0x07F907F9, 0x000007F9,
0x08F808F8, 0x000008F8, 0x08F808F8, 0x000008F8,
0x09F709F7, 0x000009F7, 0x09F709F7, 0x000009F7,
0x0AF60AF6, 0x00000AF6, 0x0AF60AF6, 0x00000AF6,
0x0BF50BF5, 0x00000BF5, 0x0BF50BF5, 0x00000BF5,
0x0CF40CF4, 0x00000CF4, 0x0CF40CF4, 0x00000CF4,
0x0DF30DF3, 0x00000DF3, 0x0DF30DF3, 0x00000DF3,
0x0EF20EF2, 0x00000EF2, 0x0EF20EF2, 0x00000EF2,
0x0FF10FF1, 0x00000FF1, 0x0FF10FF1, 0x00000FF1,
0x10F010F0, 0x000010F0, 0x10F010F0, 0x000010F0,
0x11EF11EF, 0x000011EF, 0x11EF11EF, 0x000011EF,
0x12EE12EE, 0x000012EE, 0x12EE12EE, 0x000012EE,
0x13ED13ED, 0x000013ED, 0x13ED13ED, 0x000013ED,
0x14EC14EC, 0x000014EC, 0x14EC14EC, 0x000014EC,
0x15EB15EB, 0x000015EB, 0x15EB15EB, 0x000015EB,
0x16EA16EA, 0x000016EA, 0x16EA16EA, 0x000016EA,
0x17E917E9, 0x000017E9, 0x17E917E9, 0x000017E9,
0x18E818E8, 0x000018E8, 0x18E818E8, 0x000018E8,
0x19E719E7, 0x000019E7, 0x19E719E7, 0x000019E7,
0x1AE61AE6, 0x00001AE6, 0x1AE61AE6, 0x00001AE6,
0x1BE51BE5, 0x00001BE5, 0x1BE51BE5, 0x00001BE5,
0x1CE41CE4, 0x00001CE4, 0x1CE41CE4, 0x00001CE4,
0x1DE31DE3, 0x00001DE3, 0x1DE31DE3, 0x00001DE3,
0x1EE21EE2, 0x00001EE2, 0x1EE21EE2, 0x00001EE2,
0x1FE11FE1, 0x00001FE1, 0x1FE11FE1, 0x00001FE1,
0x20E020E0, 0x000020E0, 0x20E020E0, 0x000020E0,
0x21DF21DF, 0x000021DF, 0x21DF21DF, 0x000021DF,
0x22DE22DE, 0x000022DE, 0x22DE22DE, 0x000022DE,
0x23DD23DD, 0x000023DD, 0x23DD23DD, 0x000023DD,
0x24DC24DC, 0x000024DC, 0x24DC24DC, 0x000024DC,
0x25DB25DB, 0x000025DB, 0x25DB25DB, 0x000025DB,
0x26DA26DA, 0x000026DA, 0x26DA26DA, 0x000026DA,
0x27D927D9, 0x000027D9, 0x27D927D9, 0x000027D9,
0x28D828D8, 0x000028D8, 0x28D828D8, 0x000028D8,
0x29D729D7, 0x000029D7, 0x29D729D7, 0x000029D7,
0x2AD62AD6, 0x00002AD6, 0x2AD62AD6, 0x00002AD6,
0x2BD52BD5, 0x00002BD5, 0x2BD52BD5, 0x00002BD5,
0x2CD42CD4, 0x00002CD4, 0x2CD42CD4, 0x00002CD4,
0x2DD32DD3, 0x00002DD3, 0x2DD32DD3, 0x00002DD3,
0x2ED22ED2, 0x00002ED2, 0x2ED22ED2, 0x00002ED2,
0x2FD12FD1, 0x00002FD1, 0x2FD12FD1, 0x00002FD1,
0x30D030D0, 0x000030D0, 0x30D030D0, 0x000030D0,
0x31CF31CF, 0x000031CF, 0x31CF31CF, 0x000031CF,
0x32CE32CE, 0x000032CE, 0x32CE32CE, 0x000032CE,
0x33CD33CD, 0x000033CD, 0x33CD33CD, 0x000033CD,
0x34CC34CC, 0x000034CC, 0x34CC34CC, 0x000034CC,
0x35CB35CB, 0x000035CB, 0x35CB35CB, 0x000035CB,
0x36CA36CA, 0x000036CA, 0x36CA36CA, 0x000036CA,
0x37C937C9, 0x000037C9, 0x37C937C9, 0x000037C9,
0x38C838C8, 0x000038C8, 0x38C838C8, 0x000038C8,
0x39C739C7, 0x000039C7, 0x39C739C7, 0x000039C7,
0x3AC63AC6, 0x00003AC6, 0x3AC63AC6, 0x00003AC6,
0x3BC53BC5, 0x00003BC5, 0x3BC53BC5, 0x00003BC5,
0x3CC43CC4, 0x00003CC4, 0x3CC43CC4, 0x00003CC4,
0x3DC33DC3, 0x00003DC3, 0x3DC33DC3, 0x00003DC3,
0x3EC23EC2, 0x00003EC2, 0x3EC23EC2, 0x00003EC2,
0x3FC13FC1, 0x00003FC1, 0x3FC13FC1, 0x00003FC1,
0x40C040C0, 0x000040C0, 0x40C040C0, 0x000040C0,
0x41BF41BF, 0x000041BF, 0x41BF41BF, 0x000041BF,
0x42BE42BE, 0x000042BE, 0x42BE42BE, 0x000042BE,
0x43BD43BD, 0x000043BD, 0x43BD43BD, 0x000043BD,
0x44BC44BC, 0x000044BC, 0x44BC44BC, 0x000044BC,
0x45BB45BB, 0x000045BB, 0x45BB45BB, 0x000045BB,
0x46BA46BA, 0x000046BA, 0x46BA46BA, 0x000046BA,
0x47B947B9, 0x000047B9, 0x47B947B9, 0x000047B9,
0x48B848B8, 0x000048B8, 0x48B848B8, 0x000048B8,
0x49B749B7, 0x000049B7, 0x49B749B7, 0x000049B7,
0x4AB64AB6, 0x00004AB6, 0x4AB64AB6, 0x00004AB6,
0x4BB54BB5, 0x00004BB5, 0x4BB54BB5, 0x00004BB5,
0x4CB44CB4, 0x00004CB4, 0x4CB44CB4, 0x00004CB4,
0x4DB34DB3, 0x00004DB3, 0x4DB34DB3, 0x00004DB3,
0x4EB24EB2, 0x00004EB2, 0x4EB24EB2, 0x00004EB2,
0x4FB14FB1, 0x00004FB1, 0x4FB14FB1, 0x00004FB1,
0x50B050B0, 0x000050B0, 0x50B050B0, 0x000050B0,
0x51AF51AF, 0x000051AF, 0x51AF51AF, 0x000051AF,
0x52AE52AE, 0x000052AE, 0x52AE52AE, 0x000052AE,
0x53AD53AD, 0x000053AD, 0x53AD53AD, 0x000053AD,
0x54AC54AC, 0x000054AC, 0x54AC54AC, 0x000054AC,
0x55AB55AB, 0x000055AB, 0x55AB55AB, 0x000055AB,
0x56AA56AA, 0x000056AA, 0x56AA56AA, 0x000056AA,
0x57A957A9, 0x000057A9, 0x57A957A9, 0x000057A9,
0x58A858A8, 0x000058A8, 0x58A858A8, 0x000058A8,
0x59A759A7, 0x000059A7, 0x59A759A7, 0x000059A7,
0x5AA65AA6, 0x00005AA6, 0x5AA65AA6, 0x00005AA6,
0x5BA55BA5, 0x00005BA5, 0x5BA55BA5, 0x00005BA5,
0x5CA45CA4, 0x00005CA4, 0x5CA45CA4, 0x00005CA4,
0x5DA35DA3, 0x00005DA3, 0x5DA35DA3, 0x00005DA3,
0x5EA25EA2, 0x00005EA2, 0x5EA25EA2, 0x00005EA2,
0x5FA15FA1, 0x00005FA1, 0x5FA15FA1, 0x00005FA1,
0x60A060A0, 0x000060A0, 0x60A060A0, 0x000060A0,
0x619F619F, 0x0000619F, 0x619F619F, 0x0000619F,
0x629E629E, 0x0000629E, 0x629E629E, 0x0000629E,
0x639D639D, 0x0000639D, 0x639D639D, 0x0000639D,
0x649C649C, 0x0000649C, 0x649C649C, 0x0000649C,
0x659B659B, 0x0000659B, 0x659B659B, 0x0000659B,
0x669A669A, 0x0000669A, 0x669A669A, 0x0000669A,
0x67996799, 0x00006799, 0x67996799, 0x00006799,
0x68986898, 0x00006898, 0x68986898, 0x00006898,
0x69976997, 0x00006997, 0x69976997, 0x00006997,
0x6A966A96, 0x00006A96, 0x6A966A96, 0x00006A96,
0x6B956B95, 0x00006B95, 0x6B956B95, 0x00006B95,
0x6C946C94, 0x00006C94, 0x6C946C94, 0x00006C94,
0x6D936D93, 0x00006D93, 0x6D936D93, 0x00006D93,
0x6E926E92, 0x00006E92, 0x6E926E92, 0x00006E92,
0x6F916F91, 0x00006F91, 0x6F916F91, 0x00006F91,
0x70907090, 0x00007090, 0x70907090, 0x00007090,
0x718F718F, 0x0000718F, 0x718F718F, 0x0000718F,
0x728E728E, 0x0000728E, 0x728E728E, 0x0000728E,
0x738D738D, 0x0000738D, 0x738D738D, 0x0000738D,
0x748C748C, 0x0000748C, 0x748C748C, 0x0000748C,
0x758B758B, 0x0000758B, 0x758B758B, 0x0000758B,
0x768A768A, 0x0000768A, 0x768A768A, 0x0000768A,
0x77897789, 0x00007789, 0x77897789, 0x00007789,
0x78887888, 0x00007888, 0x78887888, 0x00007888,
0x79877987, 0x00007987, 0x79877987, 0x00007987,
0x7A867A86, 0x00007A86, 0x7A867A86, 0x00007A86,
0x7B857B85, 0x00007B85, 0x7B857B85, 0x00007B85,
0x7C847C84, 0x00007C84, 0x7C847C84, 0x00007C84,
0x7D837D83, 0x00007D83, 0x7D837D83, 0x00007D83,
0x7E827E82, 0x00007E82, 0x7E827E82, 0x00007E82,
0x7F817F81, 0x00007F81, 0x7F817F81, 0x00007F81,
0x80808080, 0x00008080, 0x80808080, 0x00008080,
0x817F817F, 0x0000817F, 0x817F817F, 0x0000817F,
0x827E827E, 0x0000827E, 0x827E827E, 0x0000827E,
0x837D837D, 0x0000837D, 0x837D837D, 0x0000837D,
0x847C847C, 0x0000847C, 0x847C847C, 0x0000847C,
0x857B857B, 0x0000857B, 0x857B857B, 0x0000857B,
0x867A867A, 0x0000867A, 0x867A867A, 0x0000867A,
0x87798779, 0x00008779, 0x87798779, 0x00008779,
0x88788878, 0x00008878, 0x88788878, 0x00008878,
0x89778977, 0x00008977, 0x89778977, 0x00008977,
0x8A768A76, 0x00008A76, 0x8A768A76, 0x00008A76,
0x8B758B75, 0x00008B75, 0x8B758B75, 0x00008B75,
0x8C748C74, 0x00008C74, 0x8C748C74, 0x00008C74,
0x8D738D73, 0x00008D73, 0x8D738D73, 0x00008D73,
0x8E728E72, 0x00008E72, 0x8E728E72, 0x00008E72,
0x8F718F71, 0x00008F71, 0x8F718F71, 0x00008F71,
0x90709070, 0x00009070, 0x90709070, 0x00009070,
0x916F916F, 0x0000916F, 0x916F916F, 0x0000916F,
0x926E926E, 0x0000926E, 0x926E926E, 0x0000926E,
0x936D936D, 0x0000936D, 0x936D936D, 0x0000936D,
0x946C946C, 0x0000946C, 0x946C946C, 0x0000946C,
0x956B956B, 0x0000956B, 0x956B956B, 0x0000956B,
0x966A966A, 0x0000966A, 0x966A966A, 0x0000966A,
0x97699769, 0x00009769, 0x97699769, 0x00009769,
0x98689868, 0x00009868, 0x98689868, 0x00009868,
0x99679967, 0x00009967, 0x99679967, 0x00009967,
0x9A669A66, 0x00009A66, 0x9A669A66, 0x00009A66,
0x9B659B65, 0x00009B65, 0x9B659B65, 0x00009B65,
0x9C649C64, 0x00009C64, 0x9C649C64, 0x00009C64,
0x9D639D63, 0x00009D63, 0x9D639D63, 0x00009D63,
0x9E629E62, 0x00009E62, 0x9E629E62, 0x00009E62,
0x9F619F61, 0x00009F61, 0x9F619F61, 0x00009F61,
0xA060A060, 0x0000A060, 0xA060A060, 0x0000A060,
0xA15FA15F, 0x0000A15F, 0xA15FA15F, 0x0000A15F,
0xA25EA25E, 0x0000A25E, 0xA25EA25E, 0x0000A25E,
0xA35DA35D, 0x0000A35D, 0xA35DA35D, 0x0000A35D,
0xA45CA45C, 0x0000A45C, 0xA45CA45C, 0x0000A45C,
0xA55BA55B, 0x0000A55B, 0xA55BA55B, 0x0000A55B,
0xA65AA65A, 0x0000A65A, 0xA65AA65A, 0x0000A65A,
0xA759A759, 0x0000A759, 0xA759A759, 0x0000A759,
0xA858A858, 0x0000A858, 0xA858A858, 0x0000A858,
0xA957A957, 0x0000A957, 0xA957A957, 0x0000A957,
0xAA56AA56, 0x0000AA56, 0xAA56AA56, 0x0000AA56,
0xAB55AB55, 0x0000AB55, 0xAB55AB55, 0x0000AB55,
0xAC54AC54, 0x0000AC54, 0xAC54AC54, 0x0000AC54,
0xAD53AD53, 0x0000AD53, 0xAD53AD53, 0x0000AD53,
0xAE52AE52, 0x0000AE52, 0xAE52AE52, 0x0000AE52,
0xAF51AF51, 0x0000AF51, 0xAF51AF51, 0x0000AF51,
0xB050B050, 0x0000B050, 0xB050B050, 0x0000B050,
0xB14FB14F, 0x0000B14F, 0xB14FB14F, 0x0000B14F,
0xB24EB24E, 0x0000B24E, 0xB24EB24E, 0x0000B24E,
0xB34DB34D, 0x0000B34D, 0xB34DB34D, 0x0000B34D,
0xB44CB44C, 0x0000B44C, 0xB44CB44C, 0x0000B44C,
0xB54BB54B, 0x0000B54B, 0xB54BB54B, 0x0000B54B,
0xB64AB64A, 0x0000B64A, 0xB64AB64A, 0x0000B64A,
0xB749B749, 0x0000B749, 0xB749B749, 0x0000B749,
0xB848B848, 0x0000B848, 0xB848B848, 0x0000B848,
0xB947B947, 0x0000B947, 0xB947B947, 0x0000B947,
0xBA46BA46, 0x0000BA46, 0xBA46BA46, 0x0000BA46,
0xBB45BB45, 0x0000BB45, 0xBB45BB45, 0x0000BB45,
0xBC44BC44, 0x0000BC44, 0xBC44BC44, 0x0000BC44,
0xBD43BD43, 0x0000BD43, 0xBD43BD43, 0x0000BD43,
0xBE42BE42, 0x0000BE42, 0xBE42BE42, 0x0000BE42,
0xBF41BF41, 0x0000BF41, 0xBF41BF41, 0x0000BF41,
0xC040C040, 0x0000C040, 0xC040C040, 0x0000C040,
0xC13FC13F, 0x0000C13F, 0xC13FC13F, 0x0000C13F,
0xC23EC23E, 0x0000C23E, 0xC23EC23E, 0x0000C23E,
0xC33DC33D, 0x0000C33D, 0xC33DC33D, 0x0000C33D,
0xC43CC43C, 0x0000C43C, 0xC43CC43C, 0x0000C43C,
0xC53BC53B, 0x0000C53B, 0xC53BC53B, 0x0000C53B,
0xC63AC63A, 0x0000C63A, 0xC63AC63A, 0x0000C63A,
0xC739C739, 0x0000C739, 0xC739C739, 0x0000C739,
0xC838C838, 0x0000C838, 0xC838C838, 0x0000C838,
0xC937C937, 0x0000C937, 0xC937C937, 0x0000C937,
0xCA36CA36, 0x0000CA36, 0xCA36CA36, 0x0000CA36,
0xCB35CB35, 0x0000CB35, 0xCB35CB35, 0x0000CB35,
0xCC34CC34, 0x0000CC34, 0xCC34CC34, 0x0000CC34,
0xCD33CD33, 0x0000CD33, 0xCD33CD33, 0x0000CD33,
0xCE32CE32, 0x0000CE32, 0xCE32CE32, 0x0000CE32,
0xCF31CF31, 0x0000CF31, 0xCF31CF31, 0x0000CF31,
0xD030D030, 0x0000D030, 0xD030D030, 0x0000D030,
0xD12FD12F, 0x0000D12F, 0xD12FD12F, 0x0000D12F,
0xD22ED22E, 0x0000D22E, 0xD22ED22E, 0x0000D22E,
0xD32DD32D, 0x0000D32D, 0xD32DD32D, 0x0000D32D,
0xD42CD42C, 0x0000D42C, 0xD42CD42C, 0x0000D42C,
0xD52BD52B, 0x0000D52B, 0xD52BD52B, 0x0000D52B,
0xD62AD62A, 0x0000D62A, 0xD62AD62A, 0x0000D62A,
0xD729D729, 0x0000D729, 0xD729D729, 0x0000D729,
0xD828D828, 0x0000D828, 0xD828D828, 0x0000D828,
0xD927D927, 0x0000D927, 0xD927D927, 0x0000D927,
0xDA26DA26, 0x0000DA26, 0xDA26DA26, 0x0000DA26,
0xDB25DB25, 0x0000DB25, 0xDB25DB25, 0x0000DB25,
0xDC24DC24, 0x0000DC24, 0xDC24DC24, 0x0000DC24,
0xDD23DD23, 0x0000DD23, 0xDD23DD23, 0x0000DD23,
0xDE22DE22, 0x0000DE22, 0xDE22DE22, 0x0000DE22,
0xDF21DF21, 0x0000DF21, 0xDF21DF21, 0x0000DF21,
0xE020E020, 0x0000E020, 0xE020E020, 0x0000E020,
0xE11FE11F, 0x0000E11F, 0xE11FE11F, 0x0000E11F,
0xE21EE21E, 0x0000E21E, 0xE21EE21E, 0x0000E21E,
0xE31DE31D, 0x0000E31D, 0xE31DE31D, 0x0000E31D,
0xE41CE41C, 0x0000E41C, 0xE41CE41C, 0x0000E41C,
0xE51BE51B, 0x0000E51B, 0xE51BE51B, 0x0000E51B,
0xE61AE61A, 0x0000E61A, 0xE61AE61A, 0x0000E61A,
0xE719E719, 0x0000E719, 0xE719E719, 0x0000E719,
0xE818E818, 0x0000E818, 0xE818E818, 0x0000E818,
0xE917E917, 0x0000E917, 0xE917E917, 0x0000E917,
0xEA16EA16, 0x0000EA16, 0xEA16EA16, 0x0000EA16,
0xEB15EB15, 0x0000EB15, 0xEB15EB15, 0x0000EB15,
0xEC14EC14, 0x0000EC14, 0xEC14EC14, 0x0000EC14,
0xED13ED13, 0x0000ED13, 0xED13ED13, 0x0000ED13,
0xEE12EE12, 0x0000EE12, 0xEE12EE12, 0x0000EE12,
0xEF11EF11, 0x0000EF11, 0xEF11EF11, 0x0000EF11,
0xF010F010, 0x0000F010, 0xF010F010, 0x0000F010,
0xF10FF10F, 0x0000F10F, 0xF10FF10F, 0x0000F10F,
0xF20EF20E, 0x0000F20E, 0xF20EF20E, 0x0000F20E,
0xF30DF30D, 0x0000F30D, 0xF30DF30D, 0x0000F30D,
0xF40CF40C, 0x0000F40C, 0xF40CF40C, 0x0000F40C,
0xF50BF50B, 0x0000F50B, 0xF50BF50B, 0x0000F50B,
0xF60AF60A, 0x0000F60A, 0xF60AF60A, 0x0000F60A,
0xF709F709, 0x0000F709, 0xF709F709, 0x0000F709,
0xF808F808, 0x0000F808, 0xF808F808, 0x0000F808,
0xF907F907, 0x0000F907, 0xF907F907, 0x0000F907,
0xFA06FA06, 0x0000FA06, 0xFA06FA06, 0x0000FA06,
0xFB05FB05, 0x0000FB05, 0xFB05FB05, 0x0000FB05,
0xFC04FC04, 0x0000FC04, 0xFC04FC04, 0x0000FC04,
0xFD03FD03, 0x0000FD03, 0xFD03FD03, 0x0000FD03,
0xFE02FE02, 0x0000FE02, 0xFE02FE02, 0x0000FE02,
0xFF01FF01, 0x0000FF01, 0xFF01FF01, 0x0000FF01
};
// 0x01FF01FF 0x00001FF, 0x01FF01FF 0x00001FF