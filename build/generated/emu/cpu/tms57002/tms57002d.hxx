#ifdef DASM1
    case 0x01:
      util::stream_format(stream, "abs");
      break;

    case 0x02:
      util::stream_format(stream, "neg");
      break;

    case 0x03:
      util::stream_format(stream, "add %s,a", get_memadr(opcode, 'd'));
      break;

    case 0x04:
      util::stream_format(stream, "add %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x05:
      util::stream_format(stream, "add %s,m", get_memadr(opcode, 'd'));
      break;

    case 0x06:
      util::stream_format(stream, "add %s,m", get_memadr(opcode, 'c'));
      break;

    case 0x07:
      util::stream_format(stream, "add %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x08:
      util::stream_format(stream, "adds %s", get_memadr(opcode, 'd'));
      break;

    case 0x09:
      util::stream_format(stream, "sub %s,a", get_memadr(opcode, 'd'));
      break;

    case 0x0a:
      util::stream_format(stream, "sub %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x0b:
      util::stream_format(stream, "sub %s,m", get_memadr(opcode, 'd'));
      break;

    case 0x0c:
      util::stream_format(stream, "sub %s,m", get_memadr(opcode, 'c'));
      break;

    case 0x0d:
      util::stream_format(stream, "sub %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x10:
      util::stream_format(stream, "zacc");
      break;

    case 0x11:
      util::stream_format(stream, "lacd %s", get_memadr(opcode, 'd'));
      break;

    case 0x12:
      util::stream_format(stream, "lacc %s", get_memadr(opcode, 'c'));
      break;

    case 0x13:
      util::stream_format(stream, "cmpl");
      break;

    case 0x14:
      util::stream_format(stream, "and %s,a", get_memadr(opcode, 'd'));
      break;

    case 0x15:
      util::stream_format(stream, "and %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x16:
      util::stream_format(stream, "and %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x17:
      util::stream_format(stream, "or %s,a", get_memadr(opcode, 'd'));
      break;

    case 0x18:
      util::stream_format(stream, "or %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x19:
      util::stream_format(stream, "or %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x1a:
      util::stream_format(stream, "xor %s,a", get_memadr(opcode, 'd'));
      break;

    case 0x1b:
      util::stream_format(stream, "xor %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x1c:
      util::stream_format(stream, "xor %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x21:
      util::stream_format(stream, "mpy %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x22:
      util::stream_format(stream, "mpy %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x23:
      util::stream_format(stream, "mpy creg,%s", get_memadr(opcode, 'd'));
      break;

    case 0x24:
      util::stream_format(stream, "mac %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x25:
      util::stream_format(stream, "mac a,%s", get_memadr(opcode, 'd'));
      break;

    case 0x26:
      util::stream_format(stream, "mac %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x28:
      util::stream_format(stream, "mpyu %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x29:
      util::stream_format(stream, "macu %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x2a:
      util::stream_format(stream, "macu a,%s", get_memadr(opcode, 'd'));
      break;

    case 0x2c:
      util::stream_format(stream, "ampy %s,%s,a", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x2d:
      util::stream_format(stream, "amac %s,%s,a", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x2e:
      util::stream_format(stream, "macs %s,a", get_memadr(opcode, 'c'));
      break;

    case 0x30:
      util::stream_format(stream, "zmac");
      break;

    case 0x31:
      util::stream_format(stream, "lmhd %s", get_memadr(opcode, 'd'));
      break;

    case 0x32:
      util::stream_format(stream, "lmld %s", get_memadr(opcode, 'd'));
      break;

    case 0x33:
      util::stream_format(stream, "lmhc %s", get_memadr(opcode, 'c'));
      break;

    case 0x34:
      util::stream_format(stream, "sfml");
      break;

    case 0x35:
      util::stream_format(stream, "sfmr");
      break;

    case 0x38:
      util::stream_format(stream, "wre %s,%s", get_memadr(opcode, 'd'), get_memadr(opcode, 'c'));
      break;

    case 0x39:
      util::stream_format(stream, "rde %s", get_memadr(opcode, 'c'));
      break;

#endif

#ifdef DASM2
    case 0x01:
      util::stream_format(stream, "sacc %s", get_memadr(opcode, 'c'));
      break;

    case 0x02:
      util::stream_format(stream, "sacd %s", get_memadr(opcode, 'd'));
      break;

    case 0x03:
      util::stream_format(stream, "smhd %s", get_memadr(opcode, 'd'));
      break;

    case 0x04:
      util::stream_format(stream, "smld %s", get_memadr(opcode, 'd'));
      break;

    case 0x05:
      util::stream_format(stream, "smhc %s", get_memadr(opcode, 'c'));
      break;

    case 0x06:
      util::stream_format(stream, "slmh %s", get_memadr(opcode, 'd'));
      break;

    case 0x07:
      util::stream_format(stream, "slml %s", get_memadr(opcode, 'd'));
      break;

    case 0x08:
      util::stream_format(stream, "lcaa");
      break;

    case 0x09:
      util::stream_format(stream, "lira");
      break;

    case 0x0d:
      util::stream_format(stream, "std1 %s", get_memadr(opcode, 'd'));
      break;

    case 0x0e:
      util::stream_format(stream, "ref");
      break;

    case 0x0f:
      util::stream_format(stream, "srbd %s", get_memadr(opcode, 'd'));
      break;

    case 0x10:
      util::stream_format(stream, "dis si0_l,%s", get_memadr(opcode, 'd'));
      break;

    case 0x11:
      util::stream_format(stream, "dis si0_r,%s", get_memadr(opcode, 'd'));
      break;

    case 0x12:
      util::stream_format(stream, "dis si1_l,%s", get_memadr(opcode, 'd'));
      break;

    case 0x13:
      util::stream_format(stream, "dis si1_r,%s", get_memadr(opcode, 'd'));
      break;

    case 0x14:
      util::stream_format(stream, "dimh si0_l");
      break;

    case 0x15:
      util::stream_format(stream, "dimh si0_r");
      break;

    case 0x16:
      util::stream_format(stream, "dimh si1_l");
      break;

    case 0x17:
      util::stream_format(stream, "dimh si1_r");
      break;

    case 0x18:
      util::stream_format(stream, "diml si0_l");
      break;

    case 0x19:
      util::stream_format(stream, "diml si0_r");
      break;

    case 0x1a:
      util::stream_format(stream, "diml si1_l");
      break;

    case 0x1b:
      util::stream_format(stream, "diml si1_r");
      break;

    case 0x20:
      util::stream_format(stream, "domh so0_l");
      break;

    case 0x21:
      util::stream_format(stream, "domh so0_r");
      break;

    case 0x22:
      util::stream_format(stream, "domh so1_l");
      break;

    case 0x23:
      util::stream_format(stream, "domh so1_r");
      break;

    case 0x24:
      util::stream_format(stream, "doml so0_l");
      break;

    case 0x25:
      util::stream_format(stream, "doml so0_r");
      break;

    case 0x26:
      util::stream_format(stream, "doml so1_l");
      break;

    case 0x27:
      util::stream_format(stream, "doml so1_r");
      break;

    case 0x30:
      util::stream_format(stream, "lpd %s", get_memadr(opcode, 'd'));
      break;

    case 0x31:
      util::stream_format(stream, "lpc %s", get_memadr(opcode, 'c'));
      break;

    case 0x38:
      util::stream_format(stream, "raov");
      break;

    case 0x42:
      util::stream_format(stream, "incd");
      break;

    case 0x0c:
      util::stream_format(stream, "ld0t %s", get_memadr(opcode, 'd'));
      break;

    case 0x1c:
      util::stream_format(stream, "dos so0_l,%s", get_memadr(opcode, 'd'));
      break;

    case 0x1d:
      util::stream_format(stream, "dos so0_r,%s", get_memadr(opcode, 'd'));
      break;

    case 0x1e:
      util::stream_format(stream, "dos so1_l,%s", get_memadr(opcode, 'd'));
      break;

    case 0x1f:
      util::stream_format(stream, "dos so1_r,%s", get_memadr(opcode, 'd'));
      break;

    case 0x3a:
      util::stream_format(stream, "rmov");
      break;

    case 0x3c:
      util::stream_format(stream, "raom");
      break;

    case 0x3d:
      util::stream_format(stream, "saom");
      break;

    case 0x40:
      util::stream_format(stream, "rmom");
      break;

    case 0x41:
      util::stream_format(stream, "smom");
      break;

    case 0x44:
      util::stream_format(stream, "ldpk 0");
      break;

    case 0x45:
      util::stream_format(stream, "ldpk 1");
      break;

    case 0x48:
      util::stream_format(stream, "scrm 32");
      break;

    case 0x49:
      util::stream_format(stream, "scrm 16h");
      break;

    case 0x4a:
      util::stream_format(stream, "scrm 16l");
      break;

    case 0x4b:
      util::stream_format(stream, "scrm <3>");
      break;

    case 0x50:
      util::stream_format(stream, "sfao 0");
      break;

    case 0x51:
      util::stream_format(stream, "sfao 7");
      break;

    case 0x54:
      util::stream_format(stream, "sfai 0");
      break;

    case 0x55:
      util::stream_format(stream, "sfai -1");
      break;

    case 0x58:
      util::stream_format(stream, "sfma 0");
      break;

    case 0x59:
      util::stream_format(stream, "sfma 2");
      break;

    case 0x5a:
      util::stream_format(stream, "sfma 4");
      break;

    case 0x5b:
      util::stream_format(stream, "sfma -16");
      break;

    case 0x60:
      util::stream_format(stream, "sfmo 0");
      break;

    case 0x61:
      util::stream_format(stream, "sfmo 2");
      break;

    case 0x62:
      util::stream_format(stream, "sfmo 4");
      break;

    case 0x63:
      util::stream_format(stream, "sfmo -8");
      break;

    case 0x68:
      util::stream_format(stream, "rnd 48");
      break;

    case 0x69:
      util::stream_format(stream, "rnd 32");
      break;

    case 0x6a:
      util::stream_format(stream, "rnd 24");
      break;

    case 0x6b:
      util::stream_format(stream, "rnd 20");
      break;

    case 0x6c:
      util::stream_format(stream, "rnd 16");
      break;

    case 0x6d:
      util::stream_format(stream, "rnd <5>");
      break;

    case 0x6e:
      util::stream_format(stream, "rnd <6>");
      break;

    case 0x6f:
      util::stream_format(stream, "rnd <7>");
      break;

#endif

#ifdef DASM3
    case 0x08:
      util::stream_format(stream, "idle");
      break;

    case 0x10:
      util::stream_format(stream, "rptk %02x", opcode & 0xff);
      break;

    case 0x18:
      util::stream_format(stream, "lcak %02x", opcode & 0xff);
      break;

    case 0x20:
      util::stream_format(stream, "lirk %02x", opcode & 0xff);
      break;

    case 0x28:
      util::stream_format(stream, "lbrk %02x", opcode & 0xff);
      break;

    case 0x40:
      util::stream_format(stream, "lcac %02x", opcode & 0xff);
      break;

    case 0x48:
      util::stream_format(stream, "b %02x", opcode & 0xff);
      break;

    case 0x50:
      util::stream_format(stream, "bgz %02x", opcode & 0xff);
      break;

    case 0x58:
      util::stream_format(stream, "blz %02x", opcode & 0xff);
      break;

    case 0x60:
      util::stream_format(stream, "bnz %02x", opcode & 0xff);
      break;

    case 0x70:
      util::stream_format(stream, "bioz %02x", opcode & 0xff);
      break;

    case 0x78:
      util::stream_format(stream, "bv %02x", opcode & 0xff);
      break;

#endif

