/* GBZ80 Static Disassembler
 *
 * Copyright (C) 2018 moecmks
 * This file is part of KS3578.
 * 
 * do What The Fuck you want to Public License
 * 
 * Version 1.0, March 2000
 * Copyright (C) 2000 Banlu Kemiyatorn (]d).
 * 136 Nives 7 Jangwattana 14 Laksi Bangkok
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * 
 * Ok, the purpose of this license is simple
 * and you just
 * 
 * DO WHAT THE FUCK YOU WANT TO.
 */
 
#include "conf.h"
#include "gameboy.h"
#include "list.h"

#ifdef _WIN32
# include <Windows.h>
#endif 

static char *g_lutctype[256];
static char *g_lutanclic[256];
static char *g_lutcurlic[256];
static unsigned short g_addrb = 0;

struct romheader {
  char title[16];
  short curlic;
  char sgb;
  unsigned char ctype;
  unsigned char promsize;
  unsigned char ramsize;
  unsigned char targetcode;
  unsigned char anclic;
  unsigned char maskver;
  unsigned char hdcrc;
  unsigned short gcrc;
};

static 
void kinit (void) {

  static int _init = 0;

  if (_init != 0)
    return ;
  else 
    _init = 1;

  memset (g_lutctype, 0, sizeof (g_lutctype));
  memset (g_lutanclic, 0, sizeof (g_lutanclic));
  memset (g_lutcurlic, 0, sizeof (g_lutcurlic));

  g_lutctype[0x00] = "ROM ONLY";
  g_lutctype[0x01] = "ROM+MBC1";
  g_lutctype[0x02] = "ROM+MBC1+RAM";
  g_lutctype[0x03] = "ROM+MBC1+RAM+Battery";
  g_lutctype[0x05] = "ROM+MBC2";
  g_lutctype[0x06] = "ROM+MBC2+Battery";
  g_lutctype[0x08] = "ROM+RAM";
  g_lutctype[0x09] = "ROM+RAM+Battery";
  g_lutctype[0x0B] = "ROM+MMM01";
  g_lutctype[0x0C] = "ROM+MMM01+RAM";
  g_lutctype[0x0D] = "ROM+MMM01+RAM+Battery";
  g_lutctype[0x0F] = "ROM+MBC3+Battery+Timer";
  g_lutctype[0x10] = "ROM+MBC3+RAM+Battery+Timer";
  g_lutctype[0x11] = "ROM+MBC3";
  g_lutctype[0x12] = "ROM+MBC3+RAM";
  g_lutctype[0x13] = "ROM+MBC3+RAM+Battery";
  g_lutctype[0x15] = "ROM+MBC4";
  g_lutctype[0x16] = "ROM+MBC4+RAM";
  g_lutctype[0x17] = "ROM+MBC4+RAM+Battery";
  g_lutctype[0x19] = "ROM+MBC5";
  g_lutctype[0x1A] = "ROM+MBC5+RAM";
  g_lutctype[0x1B] = "ROM+MBC5+RAM+Battery";
  g_lutctype[0x1C] = "ROM+MBC5+Rumble";
  g_lutctype[0x1D] = "ROM+MBC5+RAM+Rumble";
  g_lutctype[0x1E] = "ROM+MBC5+RAM+Battery+Rumble";
  g_lutctype[0x22] = "ROM+MBC5+Tilt";
  g_lutctype[0xFC] = "Nintendo Pocket Camera";
  g_lutctype[0xFD] = "Bandai TAMA5";
  g_lutctype[0xFE] = "Hudson HuC-3";
  g_lutctype[0xFF] = "Hudson HuC-1";

  /* Settings old licensee desc init --*/
  g_lutanclic[0x00] = "None";
  g_lutanclic[0x01] = "Nintendo"; /* homepage:https://www.nintendo.com */
  g_lutanclic[0x08] = "Capcom"; /* homepage:http://www.capcom.com*/
  g_lutanclic[0x09] = "Hot B Games"; /* wiki:https://en.wikipedia.org/wiki/Category:Hot_B_games */
  g_lutanclic[0x0A] = "Jaleco"; /* wiki:https://en.wikipedia.org/wiki/Jaleco*/ 
  g_lutanclic[0x0B] = "Coconuts Japan"; /* misc link:https://www.genkivideogames.com/japanese_imported_video_games.asp?pagetoshow=search&keywordtext=Coconuts%20Japan&searchtype=publisher*/
  g_lutanclic[0x0C] = "Elite Systems";/*wiki: https://en.wikipedia.org/wiki/Elite_Systems*/
  g_lutanclic[0x13] = "EA"; /*homepage: https://www.ea.com/zh-cn */
  g_lutanclic[0x18] = "Hudson Soft"; /*homepage: http://www.hudsonsoft.net/what-we-do/ */
  g_lutanclic[0x19] = "ITC Entertainment"; /*wiki: https://en.wikipedia.org/wiki/ITC_Entertainment */
  g_lutanclic[0x1A] = "Yanoman"; /* MobyGames:https://www.mobygames.com/company/yanoman-corporation */
  g_lutanclic[0x1D] = "Nippon Clary"; /* giantbomb:https://www.giantbomb.com/nippon-clary-business/3010-6837/ */
  g_lutanclic[0x1F] = "Virgin"; /* wiki:https://en.wikipedia.org/wiki/Virgin_Interactive */
                                             /* homepage: https://www.virgingames.com/quick-login */
  g_lutanclic[0x24] = "PCM Complete"; /* https://segaretro.org/PCM_Complete | https://www.mobygames.com/company/pcm-complete */
  g_lutanclic[0x25] = "San-X"; /* homepage http://www.san-x.jp*/
  g_lutanclic[0x28] = "Kotobuki Systems";/*wiki: https://en.wikipedia.org/wiki/Kemco*/
  g_lutanclic[0x29] = "SETA"; /*wiki: https://en.wikipedia.org/wiki/SETA_Corporation */
  g_lutanclic[0x30] = "Atari,SA"; /*wiki: https://en.wikipedia.org/wiki/Atari,_SA */
  g_lutanclic[0x31] = "Nintendo"; /* homepage:https://www.nintendo.com */
  g_lutanclic[0x32] = "Bandai"; /*homepage: http://www.bandai.com */
  g_lutanclic[0x33] = "GameBoyColor"; /*new licensee */
  g_lutanclic[0x34] = "Konami"; /*homepage: https://www.konami.com/en/*/
  g_lutanclic[0x35] = "Hector"; /*N/A */
  g_lutanclic[0x38] = "Capcom"; /* homepage:http://www.capcom.com*/
  g_lutanclic[0x39] = "Banpresto"; /* homepage:http://www.banpresto.jp/prize/0008.html*/
  g_lutanclic[0x3C] = "Entertainment i"; /* truncated, see http://gbdev.gg8.se/wiki/articles/Gameboy_ROM_Header_Info#Licensee*/
  g_lutanclic[0x3E] = "Gremlin"; /* wiki: https://en.wikipedia.org/wiki/Gremlin_Interactive */
  g_lutanclic[0x41] = "Ubisoft"; /*homepage: https://www.ubisoft.com/en-US/ */
  g_lutanclic[0x42] = "Atlus"; /*homepage: https://atlus.com*/ 
  g_lutanclic[0x44] = "Malibu"; /*swiki: https://strategywiki.org/wiki/Category:Malibu*/ 
  g_lutanclic[0x46] = "Angel"; /*N/A*/ 
  g_lutanclic[0x47] = "Spectrum HoloByte"; /*wiki: https://en.wikipedia.org/wiki/Spectrum_HoloByte*/
  g_lutanclic[0x49] = "Irem"; /* wiki: https://en.wikipedia.org/wiki/Irem */
  g_lutanclic[0x4A] = "Virgin"; /* wiki:https://en.wikipedia.org/wiki/Virgin_Interactive */
                                             /* homepage: https://www.virgingames.com/quick-login */
  g_lutanclic[0x4D] = "Malibu"; /*swiki: https://strategywiki.org/wiki/Category:Malibu*/ 
  g_lutanclic[0x4F] = "US.Gold"; /*wiki: https://en.wikipedia.org/wiki/U.S._Gold */
  g_lutanclic[0x50] = "Absolute"; /*homepgae:http://www.absolutegamez.com */
  g_lutanclic[0x51] = "Acclaim"; /*wiki: https://en.wikipedia.org/wiki/Acclaim_Games*/
  g_lutanclic[0x52] = "Activision"; /*homepage: https://www.activision.com*/  
  g_lutanclic[0x53] = "Sammy"; /*wiki: https://en.wikipedia.org/wiki/Sammy_Corporation*/
  g_lutanclic[0x54] = "GameTek"; /*wiki: https://en.wikipedia.org/wiki/GameTek*/
  g_lutanclic[0x55] = "Park Place"; /*maybe???: https://en.wikipedia.org/wiki/List_of_Jurassic_Park_video_games*/
  g_lutanclic[0x56] = "LJN"; /*avgn: http://avgn.wikia.com/wiki/LJN*/  
  g_lutanclic[0x57] = "MATCHBOX"; /*homepage: http://play.matchbox.com/en_US/*/
  g_lutanclic[0x59] = "Milton Bradley"; /*wiki: https://en.wikipedia.org/wiki/Milton_Bradley_Company*/
  g_lutanclic[0x5A] = "Mindscape"; /*wiki: https://en.wikipedia.org/wiki/Mindscape*/
  g_lutanclic[0x5B] = "Romstar"; /*wiki: https://en.wikipedia.org/wiki/Romstar*/  
  g_lutanclic[0x5C] = "Kaga Create"; /*wiki: https://en.wikipedia.org/wiki/Kaga_Create*/
  g_lutanclic[0x5D] = "Tradewest"; /*wiki: https://en.wikipedia.org/wiki/Tradewest*/
  g_lutanclic[0x60] = "Titus"; /*wiki: https://en.wikipedia.org/wiki/Titus_Interactive*/
  g_lutanclic[0x61] = "Virgin"; /* wiki:https://en.wikipedia.org/wiki/Virgin_Interactive */
                                             /* homepage: https://www.virgingames.com/quick-login */
  g_lutanclic[0x67] = "Ocean"; /*wiki: https://en.wikipedia.org/wiki/Ocean_Software*/  
  g_lutanclic[0x69] = "EA"; /*homepage: https://www.ea.com/zh-cn */
  g_lutanclic[0x6E] = "Elite Systems";/*wiki: https://en.wikipedia.org/wiki/Elite_Systems*/
  g_lutanclic[0x6F] = "Electro Brain";/*wiki: https://en.wikipedia.org/wiki/Electro_Brain*/
  g_lutanclic[0x70] = "Atari,SA"; /*wiki: https://en.wikipedia.org/wiki/Atari,_SA */
  g_lutanclic[0x71] = "Interplay"; /*wiki: https://en.wikipedia.org/wiki/Interplay_Entertainment*/
  g_lutanclic[0x72] = "Brøderbund"; /*moby: https://www.mobygames.com/company/brderbund-software-inc*/  
  g_lutanclic[0x73] = "Sculptured"; /*maybe??: http://closinglogogroup.wikia.com/wiki/Sculptured_Software,_Inc.*/
  g_lutanclic[0x75] = "SCi Games"; /*wiki: https://en.wikipedia.org/wiki/SCi_Games*/  
  g_lutanclic[0x78] = "THQ"; /*source is:t*hq wiki: https://en.wikipedia.org/wiki/THQ*/
  g_lutanclic[0x79] = "Accolade"; /*wiki: https://en.wikipedia.org/wiki/Accolade_(game_company)*/
  g_lutanclic[0x7A] = "Triffix"; /*wiki: https://en.wikipedia.org/wiki/Triffix_Entertainment*/
  g_lutanclic[0x7C] = "MicroProse"; /*homepage: http://www.microprose.com*/  
  g_lutanclic[0x7F] = "Kemco";/*wiki: https://en.wikipedia.org/wiki/Kemco*/
  g_lutanclic[0x80] = "Misawa"; /*nseen64: https://www.unseen64.net/tag/misawa-entertainment/*/
  g_lutanclic[0x83] = "LOZC G"; /*wiki: https://en.wikipedia.org/wiki/Category:LOZC_G._Amusements_games*/
  g_lutanclic[0x86] = "Tokuma Shoten"; /*wiki: https://en.wikipedia.org/wiki/Tokuma_Shoten*/  
  g_lutanclic[0x8B] = "Blue Planet"; /*wiki: https://en.wikipedia.org/wiki/Blue_Planet_Software*/
  g_lutanclic[0x8C] = "Tokai Communications"; /*wiki: https://en.wikipedia.org/wiki/Tokai_Communications*/
  g_lutanclic[0x8E] = "APE Games"; /*homepage: http://www.apegames.com*/
  g_lutanclic[0x8F] = "I'Max"; /*No find infos */  
  g_lutanclic[0x91] = "Spike Chunsoft"; /*wiki: https://en.wikipedia.org/wiki/Spike_Chunsoft*/
  g_lutanclic[0x92] = "Video System"; /*No find infos*/  
  g_lutanclic[0x93] = "Tsuburava"; /*No find infos */
  g_lutanclic[0x95] = "Varie"; /*wiki: https://en.wikipedia.org/wiki/Varie*/  
  g_lutanclic[0x96] = "Yonezawa PR21"; /*wiki: https://en.wikipedia.org/wiki/Yonezawa_PR21*/
  g_lutanclic[0x97] = "Kaneko"; /*wiki: https://en.wikipedia.org/wiki/Kaneko*/
  g_lutanclic[0x99] = "Arcade"; /*wiki: https://en.wikipedia.org/wiki/Arcade_game*/
  g_lutanclic[0x9A] = "Nihon Bussan"; /*wiki: https://en.wikipedia.org/wiki/Nihon_Bussan*/  
  g_lutanclic[0x9B] = "Tecmo"; /*wiki: https://en.wikipedia.org/wiki/Tecmo*/
  g_lutanclic[0x9C] = "Disney"; /*wiki: https://en.wikipedia.org/wiki/Walt_Disney_Imagineering*/
  g_lutanclic[0x9D] = "Banpresto"; /* homepage:http://www.banpresto.jp/prize/0008.html*/
  g_lutanclic[0x9F] = "Nova"; /*No find infos*/
  g_lutanclic[0xA1] = "Hori Electric"; /* https://www.giantbomb.com/hori-electric-co-ltd/3010-5917/*/  
  g_lutanclic[0xA2] = "Bandai"; /*homepage: http://www.bandai.com */
  g_lutanclic[0xA4] = "Konami"; /*homepage: https://www.konami.com/en/*/  
  g_lutanclic[0xA6] = "Kawada"; /*No find infos*/
  g_lutanclic[0xA7] = "Takara"; /*wiki: https://en.wikipedia.org/wiki/Takara**/
  g_lutanclic[0xA9] = "Technōs Japan"; /*wiki: https://en.wikipedia.org/wiki/Technōs_Japan*/
  g_lutanclic[0xAA] = "Brøderbund"; /*moby: https://www.mobygames.com/company/brderbund-software-inc*/  
  g_lutanclic[0xAC] = "Toei Animation"; /*homepage: http://toei-animation-usa.com*/  
  g_lutanclic[0xAD] = "Toho"; /*No find infos*/
  g_lutanclic[0xAF] = "Namco"; /*homepage: https://www.bandainamcoent.com*/  
  g_lutanclic[0xB0] = "Acclaim"; /*wiki: https://en.wikipedia.org/wiki/Acclaim_Games*/
  g_lutanclic[0xB1] = "ASCII|Nexoft"; /*moby: http://www.mobygames.com/company/nexoft-corporation*/
  g_lutanclic[0xB2] = "Bandai"; /*homepage: http://www.bandai.com */
  g_lutanclic[0xB4] = "Enix"; /*homepage: https://en.wikipedia.org/wiki/Enix*/  
  g_lutanclic[0xB6] = "HAL"; /*wiki: https://en.wikipedia.org/wiki/HAL_Laboratory*/
  g_lutanclic[0xB7] = "SNK"; /*wiki: https://en.wikipedia.org/wiki/SNK*/ 
  g_lutanclic[0xB9] = "Pony Canyon"; /*wiki: https://en.wikipedia.org/wiki/Pony_Canyon*/
  g_lutanclic[0xBA] = "Culture Brain"; /*wiki: https://en.wikipedia.org/wiki/Culture_Brain*/  
  g_lutanclic[0xBB] = "Sunsoft"; /*wiki: https://en.wikipedia.org/wiki/Sunsoft*/
  g_lutanclic[0xBD] = "Sony Imagesoft"; /*wiki: https://en.wikipedia.org/wiki/Sony_Imagesoft*/
  g_lutanclic[0xBF] = "Sammy"; /*wiki: https://en.wikipedia.org/wiki/Sammy_Corporation*/
  g_lutanclic[0xC0] = "Taito"; /*wiki: https://en.wikipedia.org/wiki/Taito*/  
  g_lutanclic[0xC2] = "Kemco";/*wiki: https://en.wikipedia.org/wiki/Kemco*/
  g_lutanclic[0xC3] = "Square"; /*wiki: https://en.wikipedia.org/wiki/Square_(company)*/
  g_lutanclic[0xC4] = "Tokuma Shoten"; /*wiki: https://en.wikipedia.org/wiki/Tokuma_Shoten*/  
  g_lutanclic[0xC5] = "Data East"; /*wiki: https://en.wikipedia.org/wiki/Data_East*/  
  g_lutanclic[0xC6] = "Tonkin House"; /*wiki: https://en.wikipedia.org/wiki/Category:Tonkin_House_games*/
  g_lutanclic[0xC8] = "Koei"; /*wiki: https://en.wikipedia.org/wiki/Koei*/  
  g_lutanclic[0xC9] = "UFL"; /*No find infos*/
  g_lutanclic[0xCA] = "Ultra"; /*wiki: https://en.wikipedia.org/wiki/Ultra_Games*/
  g_lutanclic[0xCB] = "VAP"; /*wiki: https://en.wikipedia.org/wiki/VAP_%28company%29*/   
  g_lutanclic[0xCC] = "Use"; /*No Find infos*/
  g_lutanclic[0xCD] = "Meldac"; /*wiki: https://en.wikipedia.org/wiki/Meldac*/
  g_lutanclic[0xCE] = "Pony Canyon"; /*wiki: https://en.wikipedia.org/wiki/Pony_Canyon*/
  g_lutanclic[0xCF] = "Angel"; /*N/A*/ 
  g_lutanclic[0xD0] = "Taito"; /*wiki: https://en.wikipedia.org/wiki/Taito*/ 
  g_lutanclic[0xD1] = "SOFEL"; /*wiki: https://en.wikipedia.org/wiki/SOFEL*/
  g_lutanclic[0xD2] = "Quest"; /*No find infos*/  
  g_lutanclic[0xD3] = "Sigma Enterprises"; /*maybe?: http://sigma-enterprises.com*/
  g_lutanclic[0xD4] = "Ask Kodansha"; /*https://www.giantbomb.com/ask-kodansha/3010-3528/*/
  g_lutanclic[0xD6] = "Kaga Create"; /*wiki: https://en.wikipedia.org/wiki/Kaga_Create*/
  g_lutanclic[0xD7] = "Copya Systems"; /*wiki: https://en.wikipedia.org/wiki/Category:Copya_Systems_games*/
  g_lutanclic[0xD9] = "Banpresto"; /* homepage:http://www.banpresto.jp/prize/0008.html*/
  g_lutanclic[0xDA] = "Tomy"; /*wiki: https://en.wikipedia.org/wiki/Tomy*/  
  g_lutanclic[0xDB] = "LJN"; /*avgn: http://avgn.wikia.com/wiki/LJN*/   
  g_lutanclic[0xDD] = "Masaya Games"; /*wiki: https://en.wikipedia.org/wiki/Masaya_Games*/
  g_lutanclic[0xDE] = "Human"; /*No find infos */  
  g_lutanclic[0xDF] = "Altron"; /*wiki: https://en.wikipedia.org/wiki/Altron*/
  g_lutanclic[0xE0] = "Jaleco"; /* wiki:https://en.wikipedia.org/wiki/Jaleco*/ 
  g_lutanclic[0xE1] = "Towa Chiki"; /*wiki: https://en.wikipedia.org/wiki/Towa_Chiki*/  
  g_lutanclic[0xE2] = "Uutaka"; /*No find infos*/
  g_lutanclic[0xE3] = "Varie"; /*wiki: https://en.wikipedia.org/wiki/Varie*/  
  g_lutanclic[0xE5] = "Epoch"; /*wiki: https://en.wikipedia.org/wiki/Epoch_Co.*/
  g_lutanclic[0xE7] = "Athena"; /*wiki: https://en.wikipedia.org/wiki/Athena_(company)*/
  g_lutanclic[0xE8] = "Asmik ACE"; /*wiki: https://en.wikipedia.org/wiki/Asmik_Ace*/  
  g_lutanclic[0xE9] = "Natsume"; /*Homepage: http://www.natsume.com*/
  g_lutanclic[0xEA] = "King_Records"; /*wiki: https://en.wikipedia.org/wiki/King_Records_(Japan)*/ 
  g_lutanclic[0xEB] = "Atlus"; /*homepage: https://atlus.com*/ 
  g_lutanclic[0xEC] = "Epic Records"; /*wiki: https://en.wikipedia.org/wiki/Epic_Records_Japan*/
  g_lutanclic[0xEE] = "IGS"; /*wiki: https://en.wikipedia.org/wiki/International_Games_System*/  
  g_lutanclic[0xF0] = "a wave"; /*No find infos*/
  g_lutanclic[0xF3] = "Extreme Entertainment"; /**Moby: https://www.mobygames.com/company/extreme-entertainment-group-inc */
  g_lutanclic[0xFF] = "LJN"; /*avgn: http://avgn.wikia.com/wiki/LJN*/ 

  g_lutcurlic[0] = "None";
  g_lutcurlic[1] = "Nintendo"; /* homepage:https://www.nintendo.com */
  g_lutcurlic[8] = "Capcom"; /* homepage:http://www.capcom.com*/
  g_lutcurlic[13] = "EA"; /*homepage: https://www.ea.com/zh-cn */
  g_lutcurlic[18] = "Hudson Soft"; /*homepage: http://www.hudsonsoft.net/what-we-do/ */
  g_lutcurlic[19] = "B-AI";   
  g_lutcurlic[20] = "KSS"; /* wiki: https://en.wikipedia.org/wiki/KSS_(company) */
  g_lutcurlic[22] = "POW";                                      /* homepage: https://www.virgingames.com/quick-login */
  g_lutcurlic[24] = "PCM Complete"; /* https://segaretro.org/PCM_Complete | https://www.mobygames.com/company/pcm-complete */
  g_lutcurlic[25] = "San-X"; /* homepage http://www.san-x.jp*/
  g_lutcurlic[28] = "Kemco Japan";/*homepage: https://kemco-games.com/global/index.html*/
  g_lutcurlic[29] = "SETA"; /*wiki: https://en.wikipedia.org/wiki/SETA_Corporation */
  g_lutcurlic[30] = "Viacom"; /*wiki: https://en.wikipedia.org/wiki/Viacom */
  g_lutcurlic[31] = "Nintendo"; /* homepage:https://www.nintendo.com */
  g_lutcurlic[32] = "Bandai"; /*bandia? homepage: http://www.bandai.com */
  g_lutcurlic[33] = "Ocean"; /*wiki: https://en.wikipedia.org/wiki/Ocean_Software*/  
  g_lutcurlic[34] = "Konami"; /*homepage: https://www.konami.com/en/*/
  g_lutcurlic[35] = "Hector"; /*N/A */
  g_lutcurlic[37] = "Taito"; /*wiki: https://en.wikipedia.org/wiki/Taito*/   
  g_lutcurlic[38] = "Hudson"; /*homepage: http://www.hudsonsoft.net/what-we-do/ */
  g_lutcurlic[39] = "Banpresto"; /* homepage:http://www.banpresto.jp/prize/0008.html*/
  g_lutcurlic[41] = "Ubisoft"; /*homepage: https://www.ubisoft.com/en-US/ */
  g_lutcurlic[42] = "Atlus"; /*homepage: https://atlus.com*/ 
  g_lutcurlic[44] = "Malibu"; /*swiki: https://strategywiki.org/wiki/Category:Malibu*/ 
  g_lutcurlic[46] = "Angel"; /*N/A*/ 
  g_lutcurlic[47] = "Pullet-Proof";
  g_lutcurlic[49] = "Irem"; /* wiki: https://en.wikipedia.org/wiki/Irem */
  g_lutcurlic[50] = "Absolute"; /*homepgae:http://www.absolutegamez.com */
  g_lutcurlic[51] = "Acclaim"; /*wiki: https://en.wikipedia.org/wiki/Acclaim_Games*/
  g_lutcurlic[52] = "Activision"; /*homepage: https://www.activision.com*/  
  g_lutcurlic[53] = "American Sammy"; /*wiki: https://en.wikipedia.org/wiki/Sammy_Corporation*/
  g_lutcurlic[54] = "Konami"; /*homepage: https://www.konami.com/en/*/
  g_lutcurlic[55] = "Hi-TECH"; 
  g_lutcurlic[56] = "LJN"; /*avgn: http://avgn.wikia.com/wiki/LJN*/  
  g_lutcurlic[57] = "MATCHBOX"; /*homepage: http://play.matchbox.com/en_US/*/
  g_lutcurlic[58] = "Mattel"; /*wiki: https://en.wikipedia.org/wiki/Mattel*/
  g_lutcurlic[59] = "Milton Bradley"; /*wiki: https://en.wikipedia.org/wiki/Milton_Bradley_Company*/
  g_lutcurlic[60] = "Titus"; /*wiki: https://en.wikipedia.org/wiki/Titus_Interactive*/
  g_lutcurlic[61] = "Virgin"; /* wiki:https://en.wikipedia.org/wiki/Virgin_Interactive */
                                             /* homepage: https://www.virgingames.com/quick-login */                                        
  g_lutcurlic[64] = "LucasArts";/*wiki: https://en.wikipedia.org/wiki/LucasArts*/
  g_lutcurlic[67] = "Ocean"; /*wiki: https://en.wikipedia.org/wiki/Ocean_Software*/  
  g_lutcurlic[69] = "EA"; /*homepage: https://www.ea.com/zh-cn */
  g_lutcurlic[70] = "Atari,SA"; /*wiki: https://en.wikipedia.org/wiki/Atari,_SA */
  g_lutcurlic[71] = "Interplay"; /*wiki: https://en.wikipedia.org/wiki/Interplay_Entertainment*/
  g_lutcurlic[72] = "Brøderbund"; /*moby: https://www.mobygames.com/company/brderbund-software-inc*/  
  g_lutcurlic[73] = "Sculptured"; /*maybe??: http://closinglogogroup.wikia.com/wiki/Sculptured_Software,_Inc.*/
  g_lutcurlic[75] = "SCi Games"; /*wiki: https://en.wikipedia.org/wiki/SCi_Games*/  
  g_lutcurlic[78] = "THQ"; /*source is:t*hq wiki: https://en.wikipedia.org/wiki/THQ*/
  g_lutcurlic[79] = "Accolade"; /*wiki: https://en.wikipedia.org/wiki/Accolade_(game_company)*/
  g_lutcurlic[80] = "Misawa"; /*nseen64: https://www.unseen64.net/tag/misawa-entertainment/*/
  g_lutcurlic[83] = "LOZC G"; /*wiki: https://en.wikipedia.org/wiki/Category:LOZC_G._Amusements_games*/
  g_lutcurlic[86] = "Tokuma Shoten"; /*wiki: https://en.wikipedia.org/wiki/Tokuma_Shoten*/  
  g_lutcurlic[87] = "Tsukuda Original"; /*https://segaretro.org/Tsukuda_Original*/
  g_lutcurlic[91] = "Spike Chunsoft"; /*wiki: https://en.wikipedia.org/wiki/Spike_Chunsoft*/
  g_lutcurlic[92] = "Video System"; /*No find infos*/  
  g_lutcurlic[93] = "Ocean"; /*wiki: https://en.wikipedia.org/wiki/Ocean_Software*/  
  g_lutcurlic[95] = "Varie"; /*wiki: https://en.wikipedia.org/wiki/Varie*/  
  g_lutcurlic[96] = "Yonezawa PR21"; /*wiki: https://en.wikipedia.org/wiki/Yonezawa_PR21*/
  g_lutcurlic[97] = "Kaneko"; /*wiki: https://en.wikipedia.org/wiki/Kaneko*/
  g_lutcurlic[99] = "Pack-In-Video"; /*wiki: https://en.wikipedia.org/wiki/Pack-In-Video*/
}

/* 
|||||| -------------- BANK-ID :%d START -------------- |||||| 
>% abs $% cc 
%fece sub_ffff:    >%ffff >%fffe >%fffc >%ffed
%fece long_ffff:   >%ffff >%fffe >%fffc >%ffed
%fece              ld $bc, %ff @@ this is comment
%fecf loc_fecf:    >%ffff >%fffe >%fffc >%ffed
%fecf              ld ($hl), $bc 
%fed0              ld ($hl), $sp  
%fed2              dec a 
%fed4              jrnz loc_fecf
%fed7              jp %ffff 

@--------------------------------------------------------------
||||||| -------------- BANK-ID :%d END   -------------- ||||||| 
call/jr/jp/ret/reti proc mark. jp mark again.
*/

struct addrmark_n {
  ks_bool ccbranch;
  ks_uint16 addr;
};
struct addrmark {
  ks_uint16 baddr;
  struct list_ *reflong_tracker;
  struct list_ *refcall_tracker;
  struct list_ *refshort_tracker;
};
struct instr_sec {
  ks_uint16 addr;
  ks_uint16 instr_len;
  ks_uint8 opcode[2];
  ks_int8 opdesc[32];
  struct addrmark *attach;
};
struct sub_proc_tree {
  struct sub_proc_tree *parent;
  struct sub_proc_tree *child;
  struct sub_proc_tree *level_n;
  struct sub_proc_tree *level_p;
# define optype_jr 0
# define optype_jp 1
# define optype_call 2
# define optype_ret 3
# define optype_reti 4
# define optype_rst 5 
  int start;
  int end;
  int envlope;
};
struct sub_proc { 
  int start;
  int end;
};
struct bank_disassembler {
  struct list_ *instr_list;
  struct list_ *armark_list;
  struct list_ *codechunk_list;
  
  union { struct { ks_uint16 F; ks_uint16 A; }; ks_uint32 AF; };
  union { struct { ks_uint16 C; ks_uint16 B; }; ks_uint32 BC; };
  union { struct { ks_uint16 E; ks_uint16 D; }; ks_uint32 DE; };
  union { struct { ks_uint16 L; ks_uint16 H; }; ks_uint32 HL; };
};
static const uint8_t cpu_lens[256] = {
/*--  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F   --*/
/*0*/ 1, 3, 1, 1, 1, 1, 2, 1, 3, 1, 1, 1, 1, 1, 2, 1, /*0*/
/*1*/ 2, 3, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, /*1*/
/*2*/ 2, 3, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, /*2*/
/*3*/ 2, 3, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, /*3*/
/*4*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*4*/
/*5*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*5*/
/*6*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*6*/
/*7*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*7*/
/*8*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*8*/
/*9*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*9*/
/*A*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*A*/
/*B*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*B*/
/*C*/ 1, 1, 3, 3, 3, 1, 2, 1, 1, 1, 3, 2, 3, 3, 2, 1, /*C*/
/*D*/ 1, 1, 3, 1, 3, 1, 2, 1, 1, 1, 3, 1, 3, 1, 2, 1, /*D*/
/*E*/ 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1, /*E*/
/*F*/ 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1  /*F*/
/*--  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F   --*/
};
int 
lr35902_getaddrmark (char *babuf, int bankid, struct list_ *armark_list /* inited */) {

  ks_uint8 *tempBank;
  ks_int32 addrcount;
  ks_uint8 opcode;

  tempBank = (ks_uint8 *) & babuf[bankid*0x4000];
  addrcount = 0;
  while (addrcount <= 0x3FFF) {
    ks_bool ccdone;
    ks_uint16 addrTemp;
    ks_int32 id;
    ks_int32 adid;
    struct addrmark *amnk;
    struct list_v *am;
    struct addrmark_n *amm;
    opcode = tempBank[addrcount];
    if (addrcount <= 0x3FFD)
      addrTemp = *(ks_uint16 *)& tempBank[addrcount+1];
    else 
      addrTemp = 0;
    ccdone = ks_true;
    adid = -1;
    switch (opcode) {
      /* jmp/jcc branch opcode case **/
 // case 0xE9:/* JP(HL) */
    case 0xC3:/* JP   */
      ccdone = ks_false;
    case 0xC2:/* JPNZ */
    case 0xD2:/* JPNC */ 
    case 0xCA:/* JPZ   */
    case 0xDA:/* JPC */
      adid = 0;
      break;
      /* call/ccc branch opcode case **/
    case 0xCD:/* CALL   */
      ccdone = ks_false;
    case 0xC4:/* CALLNZ */
    case 0xD4:/* CALLNC */ 
    case 0xCC:/* CALLZ   */
    case 0xDC:/* CALLC */
      adid = 1;
      break;
      /* jr/jcc short branch opcode case **/
    case 0x18:/* JR   */
      ccdone = ks_false;
    case 0x20:/* JRNZ */
    case 0x30:/* JRNC */ 
    case 0x28:/* JRZ   */
    case 0x38:/* JRC */
      adid = 2;
      addrTemp = (addrcount +2) + ((char)tempBank[addrcount+1]);
      addrTemp &= 0xFFFF;
    default:
      break;
    }
    if (adid >= 0) 
    {
      LIST_FOREACH (armark_list, id, am) {
        amnk = (struct addrmark *)am->obj;
        if (amnk->baddr == (addrTemp + g_addrb))
          goto skip;
        else ;
      }
      /* alloc chunk  struct addrmark * */
      amnk =(struct addrmark *)malloc (sizeof (struct addrmark));
      amnk->baddr = addrTemp + g_addrb;
      list_init (& amnk->refcall_tracker);
      list_init (& amnk->reflong_tracker);
      list_init (& amnk->refshort_tracker);
      list_insert (armark_list, -1, amnk);
  skip:
      amm = (struct addrmark_n *)malloc (sizeof (struct addrmark_n));
      amm->addr = addrcount + g_addrb;
      amm->ccbranch = ccdone;
      if (adid == 0)
        list_insert (amnk->reflong_tracker, -1, amm);
      else if (adid == 1)
        list_insert (amnk->refcall_tracker, -1, amm);
      else 
        list_insert (amnk->refshort_tracker, -1, amm);
    }
    addrcount += cpu_lens[opcode];
  }
}

int 
lr35902_bankdis (char *babuf, int bankid, struct bank_disassembler *bankdis) {

  ks_uint8 *tempBank;
  ks_int32 addrcount;
  ks_uint8 opcode;
  ks_uint8 opcode2 ;

  tempBank = (ks_uint8 *) & babuf[bankid*0x4000];
  opcode2 = 0;
  addrcount = 0;
  while (addrcount <= 0x3FFF) {
    ks_uint16 addrTemp16;
    ks_uint8 addrTemp8;
    struct instr_sec *isec;
    opcode = tempBank[addrcount];
    if (addrcount <= 0x3FFD)
      addrTemp16 = *(ks_uint16 *)& tempBank[addrcount+1];
    else 
      addrTemp16 = 0;
    addrTemp8 = (ks_uint8)addrTemp16;
    isec = (struct instr_sec *)malloc (sizeof (struct instr_sec));
    isec->attach = ks_null;
    memset (isec->opdesc, 0, sizeof (isec->opdesc));

#define __bufccpy(desc,...)\
    do {  \
      int n = sprintf ((char *)isec->opdesc, desc, __VA_ARGS__);\
      isec->opdesc[n] = 0;\
    } while (0)

    /* check register write */
    switch (opcode) {
    case 0xDB:
    case 0xEB:
    case 0xEC:
    case 0xFC:
    case 0xDD:
    case 0xED:
    case 0xFD:
    case 0xF4:
    case 0xE4:
    case 0xD3: 
    case 0xE3: __bufccpy ("undefined"); break; 
    case 0x00: __bufccpy ("nop"); break; 
    case 0x10: __bufccpy ("stop"); break; 
    case 0x76: __bufccpy ("halt"); break; 
    case 0xFB: __bufccpy ("ei"); break; 
    case 0xF3: __bufccpy ("di"); break; 
    case 0x07:  __bufccpy ("rlca"); break; 
    case 0x17:  __bufccpy ("rla"); break; 
    case 0x27:  __bufccpy ("daa"); break; 
    case 0x37:  __bufccpy ("scf"); break; 
    case 0x07+8:  __bufccpy ("rrca"); break; 
    case 0x17+8:  __bufccpy ("rra"); break; 
    case 0x27+8:  __bufccpy ("cpl"); break; 
    case 0x37+8:  __bufccpy ("ccf"); break; 
    /* LD $reg, d16 */
    case 0x01: __bufccpy ("ld bc, %%%04x", addrTemp16); break; 
    case 0x11: __bufccpy ("ld de, %%%04x", addrTemp16); break; 
    case 0x21: __bufccpy ("ld hl, %%%04x", addrTemp16); break; 
    case 0x31: __bufccpy ("ld sp, %%%04x", addrTemp16); break;  
    /* LD $reg,  d8*/
    case 0x06: __bufccpy ("ld b, %%%02x", addrTemp8); break; 
    case 0x16: __bufccpy ("ld d, %%%02x", addrTemp8); break; 
    case 0x26: __bufccpy ("ld h, %%%02x", addrTemp8); break; 
    case 0x36: __bufccpy ("ld (hl), %%%02x", addrTemp8); break;  
    case 0x06+8: __bufccpy ("ld c, %%%02x", addrTemp8); break; 
    case 0x16+8: __bufccpy ("ld e, %%%02x", addrTemp8); break; 
    case 0x26+8: __bufccpy ("ld l, %%%02x", addrTemp8); break; 
    case 0x36+8: __bufccpy ("ld a, %%%02x", addrTemp8); break;  
    /* LD ($reg),a | LD a, ($reg) */
    case 0x06-4: __bufccpy ("ld (bc), a"); break; 
    case 0x16-4: __bufccpy ("ld (de), a"); break; 
    case 0x26-4: __bufccpy ("ld (hl+), a"); break; 
    case 0x36-4: __bufccpy ("ld (hl-), a"); break;  
    case 0x06+8-4: __bufccpy ("ld a, (bc)"); break; 
    case 0x16+8-4: __bufccpy ("ld a, (de)"); break; 
    case 0x26+8-4: __bufccpy ("ld a, (hl+)"); break; 
    case 0x36+8-4: __bufccpy ("ld a, (hl-)"); break;
    
    /* LD martix */  
    case 0x40+0x00+0: __bufccpy ("ld b, b"); break;  
    case 0x40+0x00+1: __bufccpy ("ld b, c"); break;  
    case 0x40+0x00+2: __bufccpy ("ld b, d"); break;  
    case 0x40+0x00+3: __bufccpy ("ld b, e"); break;  
    case 0x40+0x00+4: __bufccpy ("ld b, h"); break;  
    case 0x40+0x00+5: __bufccpy ("ld b, l"); break;  
    case 0x40+0x00+6: __bufccpy ("ld b, (hl)"); break;  
    case 0x40+0x00+7: __bufccpy ("ld b, a"); break;  
    case 0x40+0x00+0+8: __bufccpy ("ld c, b"); break;  
    case 0x40+0x00+1+8: __bufccpy ("ld c, c"); break;  
    case 0x40+0x00+2+8: __bufccpy ("ld c, d"); break;  
    case 0x40+0x00+3+8: __bufccpy ("ld c, e"); break;  
    case 0x40+0x00+4+8: __bufccpy ("ld c, h"); break;  
    case 0x40+0x00+5+8: __bufccpy ("ld c, l"); break;  
    case 0x40+0x00+6+8: __bufccpy ("ld c, (hl)"); break;  
    case 0x40+0x00+7+8: __bufccpy ("ld c, a"); break;  

    case 0x40+0x10+0: __bufccpy ("ld d, b"); break;  
    case 0x40+0x10+1: __bufccpy ("ld d, c"); break;  
    case 0x40+0x10+2: __bufccpy ("ld d, d"); break;  
    case 0x40+0x10+3: __bufccpy ("ld d, e"); break;  
    case 0x40+0x10+4: __bufccpy ("ld d, h"); break;  
    case 0x40+0x10+5: __bufccpy ("ld d, l"); break;  
    case 0x40+0x10+6: __bufccpy ("ld d, (hl)"); break;  
    case 0x40+0x10+7: __bufccpy ("ld d, a"); break;  
    case 0x40+0x10+0+8: __bufccpy ("ld e, b"); break;  
    case 0x40+0x10+1+8: __bufccpy ("ld e, c"); break;  
    case 0x40+0x10+2+8: __bufccpy ("ld e, d"); break;  
    case 0x40+0x10+3+8: __bufccpy ("ld e, e"); break;  
    case 0x40+0x10+4+8: __bufccpy ("ld e, h"); break;  
    case 0x40+0x10+5+8: __bufccpy ("ld e, l"); break;  
    case 0x40+0x10+6+8: __bufccpy ("ld e, (hl)"); break;  
    case 0x40+0x10+7+8: __bufccpy ("ld e, a"); break;  
    
    case 0x40+0x20+0: __bufccpy ("ld h, b"); break;  
    case 0x40+0x20+1: __bufccpy ("ld h, c"); break;  
    case 0x40+0x20+2: __bufccpy ("ld h, d"); break;  
    case 0x40+0x20+3: __bufccpy ("ld h, e"); break;  
    case 0x40+0x20+4: __bufccpy ("ld h, h"); break;  
    case 0x40+0x20+5: __bufccpy ("ld h, l"); break;  
    case 0x40+0x20+6: __bufccpy ("ld h, (hl)"); break;  
    case 0x40+0x20+7: __bufccpy ("ld h, a"); break;  
    case 0x40+0x20+0+8: __bufccpy ("ld l, b"); break;  
    case 0x40+0x20+1+8: __bufccpy ("ld l, c"); break;  
    case 0x40+0x20+2+8: __bufccpy ("ld l, d"); break;  
    case 0x40+0x20+3+8: __bufccpy ("ld l, e"); break;  
    case 0x40+0x20+4+8: __bufccpy ("ld l, h"); break;  
    case 0x40+0x20+5+8: __bufccpy ("ld l, l"); break;  
    case 0x40+0x20+6+8: __bufccpy ("ld l, (hl)"); break;  
    case 0x40+0x20+7+8: __bufccpy ("ld l, a"); break;  
    
    case 0x40+0x30+0: __bufccpy ("ld (hl), b"); break;  
    case 0x40+0x30+1: __bufccpy ("ld (hl), c"); break;  
    case 0x40+0x30+2: __bufccpy ("ld (hl), d"); break;  
    case 0x40+0x30+3: __bufccpy ("ld (hl), e"); break;  
    case 0x40+0x30+4: __bufccpy ("ld (hl), h"); break;  
    case 0x40+0x30+5: __bufccpy ("ld (hl), l"); break;  
    case 0x40+0x30+7: __bufccpy ("ld (hl), a"); break;  
    case 0x40+0x30+0+8: __bufccpy ("ld a, b"); break;  
    case 0x40+0x30+1+8: __bufccpy ("ld a, c"); break;  
    case 0x40+0x30+2+8: __bufccpy ("ld a, d"); break;  
    case 0x40+0x30+3+8: __bufccpy ("ld a, e"); break;  
    case 0x40+0x30+4+8: __bufccpy ("ld a, h"); break;  
    case 0x40+0x30+5+8: __bufccpy ("ld a, l"); break;  
    case 0x40+0x30+6+8: __bufccpy ("ld a, (hl)"); break;  
    case 0x40+0x30+7+8: __bufccpy ("ld a, a"); break;  

    /* LD misc */
    case 0xE0: __bufccpy ("ld (%%%02x), a", 0xFF00+addrTemp8); break; 
    case 0xF0: __bufccpy ("ld a, (%%%02x)", 0xFF00+addrTemp8); break; 
    case 0xE0+2: __bufccpy ("ld (%%ff00+c), a"); break; 
    case 0xF0+2: __bufccpy ("ld a, (%%ff00+c)"); break; 
    case 0xF8: __bufccpy ("ld hl, sp+%%%01x", addrTemp8); break; 
    case 0xF9: __bufccpy ("ld sp, hl"); break; 
    case 0xFA: __bufccpy ("ld a, (%%%04x)", addrTemp16); break; 
    case 0xEA: __bufccpy ("ld (%%%04x), a", addrTemp16); break; 
    case 0x08: __bufccpy ("ld (%%%04x), sp", addrTemp16); break; 
    /* large alu */
    case 0x80+0x00+0: __bufccpy ("add a, b"); break;  
    case 0x80+0x00+1: __bufccpy ("add a, c"); break;  
    case 0x80+0x00+2: __bufccpy ("add a, d"); break;  
    case 0x80+0x00+3: __bufccpy ("add a, e"); break;  
    case 0x80+0x00+4: __bufccpy ("add a, h"); break;  
    case 0x80+0x00+5: __bufccpy ("add a, l"); break;  
    case 0x80+0x00+6: __bufccpy ("add a, (hl)"); break;  
    case 0x80+0x00+7: __bufccpy ("add a, a"); break;  
    case 0x80+0x00+0+8: __bufccpy ("adc a, b"); break;  
    case 0x80+0x00+1+8: __bufccpy ("adc a, c"); break;  
    case 0x80+0x00+2+8: __bufccpy ("adc a, d"); break;  
    case 0x80+0x00+3+8: __bufccpy ("adc a, e"); break;  
    case 0x80+0x00+4+8: __bufccpy ("adc a, h"); break;  
    case 0x80+0x00+5+8: __bufccpy ("adc a, l"); break;  
    case 0x80+0x00+6+8: __bufccpy ("adc a, (hl)"); break;  
    case 0x80+0x00+7+8: __bufccpy ("adc a, a"); break;  

    case 0x80+0x10+0: __bufccpy ("sub a, b"); break;  
    case 0x80+0x10+1: __bufccpy ("sub a, c"); break;  
    case 0x80+0x10+2: __bufccpy ("sub a, d"); break;  
    case 0x80+0x10+3: __bufccpy ("sub a, e"); break;  
    case 0x80+0x10+4: __bufccpy ("sub a, h"); break;  
    case 0x80+0x10+5: __bufccpy ("sub a, l"); break;  
    case 0x80+0x10+6: __bufccpy ("sub a, (hl)"); break;  
    case 0x80+0x10+7: __bufccpy ("sub a, a"); break;  
    case 0x80+0x10+0+8: __bufccpy ("sbc a, b"); break;  
    case 0x80+0x10+1+8: __bufccpy ("sbc a, c"); break;  
    case 0x80+0x10+2+8: __bufccpy ("sbc a, d"); break;  
    case 0x80+0x10+3+8: __bufccpy ("sbc a, e"); break;  
    case 0x80+0x10+4+8: __bufccpy ("sbc a, h"); break;  
    case 0x80+0x10+5+8: __bufccpy ("sbc a, l"); break;  
    case 0x80+0x10+6+8: __bufccpy ("sbc a, (hl)"); break;  
    case 0x80+0x10+7+8: __bufccpy ("sbc a, a"); break;  
    
    case 0x80+0x20+0: __bufccpy ("and a, b"); break;  
    case 0x80+0x20+1: __bufccpy ("and a, c"); break;  
    case 0x80+0x20+2: __bufccpy ("and a, d"); break;  
    case 0x80+0x20+3: __bufccpy ("and a, e"); break;  
    case 0x80+0x20+4: __bufccpy ("and a, h"); break;  
    case 0x80+0x20+5: __bufccpy ("and a, l"); break;  
    case 0x80+0x20+6: __bufccpy ("and a, (hl)"); break;  
    case 0x80+0x20+7: __bufccpy ("and a, a"); break;  
    case 0x80+0x20+0+8: __bufccpy ("xor a, b"); break;  
    case 0x80+0x20+1+8: __bufccpy ("xor a, c"); break;  
    case 0x80+0x20+2+8: __bufccpy ("xor a, d"); break;  
    case 0x80+0x20+3+8: __bufccpy ("xor a, e"); break;  
    case 0x80+0x20+4+8: __bufccpy ("xor a, h"); break;  
    case 0x80+0x20+5+8: __bufccpy ("xor a, l"); break;  
    case 0x80+0x20+6+8: __bufccpy ("xor a, (hl)"); break;  
    case 0x80+0x20+7+8: __bufccpy ("xor a, a"); break;  
    
    case 0x80+0x30+0: __bufccpy ("or a, b"); break;  
    case 0x80+0x30+1: __bufccpy ("or a, c"); break;  
    case 0x80+0x30+2: __bufccpy ("or a, d"); break;  
    case 0x80+0x30+3: __bufccpy ("or a, e"); break;  
    case 0x80+0x30+4: __bufccpy ("or a, h"); break;  
    case 0x80+0x30+5: __bufccpy ("or a, l"); break;  
    case 0x80+0x30+6: __bufccpy ("or a, (hl)"); break;  
    case 0x80+0x30+7: __bufccpy ("or a, a"); break;  
    case 0x80+0x30+0+8: __bufccpy ("cp a, b"); break;  
    case 0x80+0x30+1+8: __bufccpy ("cp a, c"); break;  
    case 0x80+0x30+2+8: __bufccpy ("cp a, d"); break;  
    case 0x80+0x30+3+8: __bufccpy ("cp a, e"); break;  
    case 0x80+0x30+4+8: __bufccpy ("cp a, h"); break;  
    case 0x80+0x30+5+8: __bufccpy ("cp a, l"); break;  
    case 0x80+0x30+6+8: __bufccpy ("cp a, (hl)"); break;  
    case 0x80+0x30+7+8: __bufccpy ("cp a, a"); break; 

      /* inc /decv wordreg */
    case 0x03: __bufccpy ("inc bc"); break; 
    case 0x13: __bufccpy ("inc de"); break; 
    case 0x23: __bufccpy ("inc hl"); break; 
    case 0x33: __bufccpy ("inc sp"); break; 
    case 0x03+8: __bufccpy ("dec bc"); break; 
    case 0x13+8: __bufccpy ("dec de"); break; 
    case 0x23+8: __bufccpy ("dec hl"); break; 
    case 0x33+8: __bufccpy ("dec sp"); break; 
      /* inc /decv sreg */
    case 0x03+1: __bufccpy ("inc b"); break; 
    case 0x13+1: __bufccpy ("inc d"); break; 
    case 0x23+1: __bufccpy ("inc h"); break; 
    case 0x33+1: __bufccpy ("inc (hl)"); break; 
    case 0x03+8+1: __bufccpy ("inc c"); break; 
    case 0x13+8+1: __bufccpy ("inc e"); break; 
    case 0x23+8+1: __bufccpy ("inc l"); break; 
    case 0x33+8+1: __bufccpy ("inc a"); break; 
    case 0x03+1+1: __bufccpy ("dec b"); break; 
    case 0x13+1+1: __bufccpy ("dec d"); break; 
    case 0x23+1+1: __bufccpy ("dec h"); break; 
    case 0x33+1+1: __bufccpy ("dec (hl)"); break; 
    case 0x03+8+1+1: __bufccpy ("dec c"); break; 
    case 0x13+8+1+1: __bufccpy ("dec e"); break; 
    case 0x23+8+1+1: __bufccpy ("dec l"); break; 
    case 0x33+8+1+1: __bufccpy ("dec a"); break; 

    /* add word */
    case 0x09: __bufccpy ("add hl, bc"); break; 
    case 0x19: __bufccpy ("add hl, de"); break; 
    case 0x29: __bufccpy ("add hl, hl"); break; 
    case 0x39: __bufccpy ("add hl, sp"); break; 

    /* jr */
    case 0x18:/* JR   */ __bufccpy ("jr loc_%04x", (g_addrb + ((((addrcount + 2) + (char)addrTemp8)) ))& 0xFFFF); break; 
    case 0x20:/* JRNZ */ __bufccpy ("jrnz loc_%04x",( g_addrb + ((((addrcount + 2) + (char)addrTemp8)) ))& 0xFFFF); break; 
    case 0x30:/* JRNC */ __bufccpy ("jrnc loc_%04x", (g_addrb + ((((addrcount + 2) + (char)addrTemp8))))& 0xFFFF); break; 
    case 0x28:/* JRZ   */ __bufccpy ("jrz loc_%04x", (g_addrb + ((((addrcount + 2) + (char)addrTemp8)) ))& 0xFFFF); break; 
    case 0x38:/* JRC */ __bufccpy ("jrc loc_%04x", (g_addrb + ((((addrcount + 2) + (char)addrTemp8)) ))& 0xFFFF); break; 
    /* call */
    case 0xCD:/* CALL   */ __bufccpy ("call sub_%04x", addrTemp16); break; 
    case 0xC4:/* CALLNZ */ __bufccpy ("callnz sub_%04x", addrTemp16); break; 
    case 0xD4:/* CALLNC */     __bufccpy ("callnc sub_%04x", addrTemp16); break; 
    case 0xCC:/* CALLZ   */   __bufccpy ("callz sub_%04x", addrTemp16); break; 
    case 0xDC:/* CALLC */ __bufccpy ("callc sub_%04x", addrTemp16); break; 
   /* jp */
    case 0xE9:/* JP(HL) */ __bufccpy ("jp (hl)"); break; 
    case 0xC3:/* JP   */ __bufccpy ("jp long_%04x", addrTemp16); break; 
    case 0xC2:/* JPNZ */ __bufccpy ("jpnz long_%04x", addrTemp16); break; 
    case 0xD2:/* JPNC */  __bufccpy ("jpnc long_%04x", addrTemp16); break; 
    case 0xCA:/* JPZ   */ __bufccpy ("jpz long_%04x", addrTemp16); break; 
    case 0xDA:/* JPC */  __bufccpy ("jpc long_%04x", addrTemp16); break; 
      /* ret */
    case 0xC0:/*RETNZ */  __bufccpy ("retnz", addrTemp16); break; 
    case 0xD0:/*RETNC */  __bufccpy ("retnc", addrTemp16); break; 
    case 0xC0+8:/*RETZ */  __bufccpy ("retz", addrTemp16); break; 
    case 0xD0+8:/*RETC */  __bufccpy ("retc", addrTemp16); break; 
    case 0xC0+8+1:/*RET */  __bufccpy ("ret", addrTemp16); break; 
    case 0xD0+8+1:/*RETI */  __bufccpy ("reti", addrTemp16); break; 
      /* push pop */
    case 0xC5:  __bufccpy ("push bc", addrTemp16); break; 
    case 0xD5:  __bufccpy ("push de", addrTemp16); break; 
    case 0xE5:  __bufccpy ("push hl", addrTemp16); break; 
    case 0xF5:  __bufccpy ("push af", addrTemp16); break; 
    case 0xC1:  __bufccpy ("pop bc", addrTemp16); break; 
    case 0xD1:  __bufccpy ("pop de", addrTemp16); break; 
    case 0xE1:  __bufccpy ("pop hl", addrTemp16); break; 
    case 0xF1:  __bufccpy ("pop af", addrTemp16); break; 
      /* rst */
    case 0xC7:  __bufccpy ("rst %%00", addrTemp16); break; 
    case 0xD7:  __bufccpy ("rst %%10", addrTemp16); break; 
    case 0xE7:  __bufccpy ("rst %%20", addrTemp16); break; 
    case 0xF7:  __bufccpy ("rst %%30", addrTemp16); break; 
    case 0xC7+8:  __bufccpy ("rst %%08", addrTemp16); break; 
    case 0xD7+8:  __bufccpy ("rst %%18", addrTemp16); break; 
    case 0xE7+8:  __bufccpy ("rst %%28", addrTemp16); break; 
    case 0xF7+8:  __bufccpy ("rst %%38", addrTemp16); break; 
      /* alu d8*/
    case 0xC6: __bufccpy ("add a, %%%02x", addrTemp8); break; 
    case 0xD6: __bufccpy ("sub a, %%%02x", addrTemp8); break; 
    case 0xE6: __bufccpy ("and a, %%%02x", addrTemp8); break; 
    case 0xF6: __bufccpy ("or a, %%%02x", addrTemp8); break; 
    case 0xC6+8: __bufccpy ("adc a, %%%02x", addrTemp8); break; 
    case 0xD6+8: __bufccpy ("sbc a, %%%02x", addrTemp8); break; 
    case 0xE6+8: __bufccpy ("xor a, %%%02x", addrTemp8); break; 
    case 0xF6+8: __bufccpy ("cp a, %%%02x", addrTemp8); break; 
      /* misc */
    case 0xE8:  __bufccpy ("add esp, %%%02x", addrTemp8); break; 
    case 0xCB:
      /* perix cb */
      opcode2 = tempBank[addrcount+1];
      switch (opcode2) {
      case 0x00+0x00+0: __bufccpy ("rlc, b"); break;  
      case 0x00+0x00+1: __bufccpy ("rlc, c"); break;  
      case 0x00+0x00+2: __bufccpy ("rlc, d"); break;  
      case 0x00+0x00+3: __bufccpy ("rlc, e"); break;  
      case 0x00+0x00+4: __bufccpy ("rlc, h"); break;  
      case 0x00+0x00+5: __bufccpy ("rlc, l"); break;  
      case 0x00+0x00+6: __bufccpy ("rlc, (hl)"); break;  
      case 0x00+0x00+7: __bufccpy ("rlc, a"); break;  
      case 0x00+0x00+0+8: __bufccpy ("rrc, b"); break;  
      case 0x00+0x00+1+8: __bufccpy ("rrc, c"); break;  
      case 0x00+0x00+2+8: __bufccpy ("rrc, d"); break;  
      case 0x00+0x00+3+8: __bufccpy ("rrc, e"); break;  
      case 0x00+0x00+4+8: __bufccpy ("rrc, h"); break;  
      case 0x00+0x00+5+8: __bufccpy ("rrc, l"); break;  
      case 0x00+0x00+6+8: __bufccpy ("rrc, (hl)"); break;  
      case 0x00+0x00+7+8: __bufccpy ("rrc, a"); break;  

      case 0x00+0x10+0: __bufccpy ("rl, b"); break;  
      case 0x00+0x10+1: __bufccpy ("rl, c"); break;  
      case 0x00+0x10+2: __bufccpy ("rl, d"); break;  
      case 0x00+0x10+3: __bufccpy ("rl, e"); break;  
      case 0x00+0x10+4: __bufccpy ("rl, h"); break;  
      case 0x00+0x10+5: __bufccpy ("rl, l"); break;  
      case 0x00+0x10+6: __bufccpy ("rl, (hl)"); break;  
      case 0x00+0x10+7: __bufccpy ("rl, a"); break;  
      case 0x00+0x10+0+8: __bufccpy ("rr, b"); break;  
      case 0x00+0x10+1+8: __bufccpy ("rr, c"); break;  
      case 0x00+0x10+2+8: __bufccpy ("rr, d"); break;  
      case 0x00+0x10+3+8: __bufccpy ("rr, e"); break;  
      case 0x00+0x10+4+8: __bufccpy ("rr, h"); break;  
      case 0x00+0x10+5+8: __bufccpy ("rr, l"); break;  
      case 0x00+0x10+6+8: __bufccpy ("rr, (hl)"); break;  
      case 0x00+0x10+7+8: __bufccpy ("rr, a"); break;  
    
      case 0x00+0x20+0: __bufccpy ("sla, b"); break;  
      case 0x00+0x20+1: __bufccpy ("sla, c"); break;  
      case 0x00+0x20+2: __bufccpy ("sla, d"); break;  
      case 0x00+0x20+3: __bufccpy ("sla, e"); break;  
      case 0x00+0x20+4: __bufccpy ("sla, h"); break;  
      case 0x00+0x20+5: __bufccpy ("sla, l"); break;  
      case 0x00+0x20+6: __bufccpy ("sla, (hl)"); break;  
      case 0x00+0x20+7: __bufccpy ("sla, a"); break;  
      case 0x00+0x20+0+8: __bufccpy ("sra, b"); break;  
      case 0x00+0x20+1+8: __bufccpy ("sra, c"); break;  
      case 0x00+0x20+2+8: __bufccpy ("sra, d"); break;  
      case 0x00+0x20+3+8: __bufccpy ("sra, e"); break;  
      case 0x00+0x20+4+8: __bufccpy ("sra, h"); break;  
      case 0x00+0x20+5+8: __bufccpy ("sra, l"); break;  
      case 0x00+0x20+6+8: __bufccpy ("sra, (hl)"); break;  
      case 0x00+0x20+7+8: __bufccpy ("sra, a"); break;  
    
      case 0x00+0x30+0: __bufccpy ("swap, b"); break;  
      case 0x00+0x30+1: __bufccpy ("swap, c"); break;  
      case 0x00+0x30+2: __bufccpy ("swap, d"); break;  
      case 0x00+0x30+3: __bufccpy ("swap, e"); break;  
      case 0x00+0x30+4: __bufccpy ("swap, h"); break;  
      case 0x00+0x30+5: __bufccpy ("swap, l"); break;  
      case 0x00+0x30+6: __bufccpy ("swap, (hl)"); break;  
      case 0x00+0x30+7: __bufccpy ("swap, a"); break;  
      case 0x00+0x30+0+8: __bufccpy ("srl, b"); break;  
      case 0x00+0x30+1+8: __bufccpy ("srl, c"); break;  
      case 0x00+0x30+2+8: __bufccpy ("srl, d"); break;  
      case 0x00+0x30+3+8: __bufccpy ("srl, e"); break;  
      case 0x00+0x30+4+8: __bufccpy ("srl, h"); break;  
      case 0x00+0x30+5+8: __bufccpy ("srl, l"); break;  
      case 0x00+0x30+6+8: __bufccpy ("srl, (hl)"); break;  
      case 0x00+0x30+7+8: __bufccpy ("srl, a"); break; 

      case 0x40+0x00+0: __bufccpy ("bit b, 0"); break;  
      case 0x40+0x00+1: __bufccpy ("bit c, 0"); break;  
      case 0x40+0x00+2: __bufccpy ("bit d, 0"); break;  
      case 0x40+0x00+3: __bufccpy ("bit e, 0"); break;  
      case 0x40+0x00+4: __bufccpy ("bit h, 0"); break;  
      case 0x40+0x00+5: __bufccpy ("bit l, 0"); break;  
      case 0x40+0x00+6: __bufccpy ("bit (hl), 0"); break;  
      case 0x40+0x00+7: __bufccpy ("bit a, 0"); break;  
      case 0x40+0x00+0+8: __bufccpy ("bit b, 1"); break;  
      case 0x40+0x00+1+8: __bufccpy ("bit c, 1"); break;  
      case 0x40+0x00+2+8: __bufccpy ("bit d, 1"); break;  
      case 0x40+0x00+3+8: __bufccpy ("bit e, 1"); break;  
      case 0x40+0x00+4+8: __bufccpy ("bit h, 1"); break;  
      case 0x40+0x00+5+8: __bufccpy ("bit l, 1"); break;  
      case 0x40+0x00+6+8: __bufccpy ("bit (hl), 1"); break;  
      case 0x40+0x00+7+8: __bufccpy ("bit a, 1"); break;  

      case 0x40+0x10+0: __bufccpy ("bit b, 2"); break;  
      case 0x40+0x10+1: __bufccpy ("bit c, 2"); break;  
      case 0x40+0x10+2: __bufccpy ("bit d, 2"); break;  
      case 0x40+0x10+3: __bufccpy ("bit e, 2"); break;  
      case 0x40+0x10+4: __bufccpy ("bit h, 2"); break;  
      case 0x40+0x10+5: __bufccpy ("bit l, 2"); break;  
      case 0x40+0x10+6: __bufccpy ("bit (hl), 2"); break;  
      case 0x40+0x10+7: __bufccpy ("bit a, 2"); break;  
      case 0x40+0x10+0+8: __bufccpy ("bit b, 3"); break;  
      case 0x40+0x10+1+8: __bufccpy ("bit c, 3"); break;  
      case 0x40+0x10+2+8: __bufccpy ("bit d, 3"); break;  
      case 0x40+0x10+3+8: __bufccpy ("bit e, 3"); break;  
      case 0x40+0x10+4+8: __bufccpy ("bit h, 3"); break;  
      case 0x40+0x10+5+8: __bufccpy ("bit l, 3"); break;  
      case 0x40+0x10+6+8: __bufccpy ("bit (hl), 3"); break;  
      case 0x40+0x10+7+8: __bufccpy ("bit a, 3"); break;  
    
      case 0x40+0x20+0: __bufccpy ("bit b, 4"); break;  
      case 0x40+0x20+1: __bufccpy ("bit c, 4"); break;  
      case 0x40+0x20+2: __bufccpy ("bit d, 4"); break;  
      case 0x40+0x20+3: __bufccpy ("bit e, 4"); break;  
      case 0x40+0x20+4: __bufccpy ("bit h, 4"); break;  
      case 0x40+0x20+5: __bufccpy ("bit l, 4"); break;  
      case 0x40+0x20+6: __bufccpy ("bit (hl), 4"); break;  
      case 0x40+0x20+7: __bufccpy ("bit a, 4"); break;  
      case 0x40+0x20+0+8: __bufccpy ("bit b, 5"); break;  
      case 0x40+0x20+1+8: __bufccpy ("bit c, 5"); break;  
      case 0x40+0x20+2+8: __bufccpy ("bit d, 5"); break;  
      case 0x40+0x20+3+8: __bufccpy ("bit e, 5"); break;  
      case 0x40+0x20+4+8: __bufccpy ("bit h, 5"); break;  
      case 0x40+0x20+5+8: __bufccpy ("bit l, 5"); break;  
      case 0x40+0x20+6+8: __bufccpy ("bit (hl), 5"); break;  
      case 0x40+0x20+7+8: __bufccpy ("bit a, 5"); break;  
    
      case 0x40+0x30+0: __bufccpy ("bit b, 6"); break;  
      case 0x40+0x30+1: __bufccpy ("bit c, 6"); break;  
      case 0x40+0x30+2: __bufccpy ("bit d, 6"); break;  
      case 0x40+0x30+3: __bufccpy ("bit e, 6"); break;  
      case 0x40+0x30+4: __bufccpy ("bit h, 6"); break;  
      case 0x40+0x30+5: __bufccpy ("bit l, 6"); break;  
      case 0x40+0x30+6: __bufccpy ("bit (hl), 6"); break;  
      case 0x40+0x30+7: __bufccpy ("bit a, 6"); break;  
      case 0x40+0x30+0+8: __bufccpy ("bit b, 7"); break;  
      case 0x40+0x30+1+8: __bufccpy ("bit c, 7"); break;  
      case 0x40+0x30+2+8: __bufccpy ("bit d, 7"); break;  
      case 0x40+0x30+3+8: __bufccpy ("bit e, 7"); break;  
      case 0x40+0x30+4+8: __bufccpy ("bit h, 7"); break;  
      case 0x40+0x30+5+8: __bufccpy ("bit l, 7"); break;  
      case 0x40+0x30+6+8: __bufccpy ("bit (hl), 7"); break;  
      case 0x40+0x30+7+8: __bufccpy ("bit a, 7"); break; 

      case 0x80+0x00+0: __bufccpy ("res b, 0"); break;  
      case 0x80+0x00+1: __bufccpy ("res c, 0"); break;  
      case 0x80+0x00+2: __bufccpy ("res d, 0"); break;  
      case 0x80+0x00+3: __bufccpy ("res e, 0"); break;  
      case 0x80+0x00+4: __bufccpy ("res h, 0"); break;  
      case 0x80+0x00+5: __bufccpy ("res l, 0"); break;  
      case 0x80+0x00+6: __bufccpy ("res (hl), 0"); break;  
      case 0x80+0x00+7: __bufccpy ("res a, 0"); break;  
      case 0x80+0x00+0+8: __bufccpy ("res b, 1"); break;  
      case 0x80+0x00+1+8: __bufccpy ("res c, 1"); break;  
      case 0x80+0x00+2+8: __bufccpy ("res d, 1"); break;  
      case 0x80+0x00+3+8: __bufccpy ("res e, 1"); break;  
      case 0x80+0x00+4+8: __bufccpy ("res h, 1"); break;  
      case 0x80+0x00+5+8: __bufccpy ("res l, 1"); break;  
      case 0x80+0x00+6+8: __bufccpy ("res (hl), 1"); break;  
      case 0x80+0x00+7+8: __bufccpy ("res a, 1"); break;  

      case 0x80+0x10+0: __bufccpy ("res b, 2"); break;  
      case 0x80+0x10+1: __bufccpy ("res c, 2"); break;  
      case 0x80+0x10+2: __bufccpy ("res d, 2"); break;  
      case 0x80+0x10+3: __bufccpy ("res e, 2"); break;  
      case 0x80+0x10+4: __bufccpy ("res h, 2"); break;  
      case 0x80+0x10+5: __bufccpy ("res l, 2"); break;  
      case 0x80+0x10+6: __bufccpy ("res (hl), 2"); break;  
      case 0x80+0x10+7: __bufccpy ("res a, 2"); break;  
      case 0x80+0x10+0+8: __bufccpy ("res b, 3"); break;  
      case 0x80+0x10+1+8: __bufccpy ("res c, 3"); break;  
      case 0x80+0x10+2+8: __bufccpy ("res d, 3"); break;  
      case 0x80+0x10+3+8: __bufccpy ("res e, 3"); break;  
      case 0x80+0x10+4+8: __bufccpy ("res h, 3"); break;  
      case 0x80+0x10+5+8: __bufccpy ("res l, 3"); break;  
      case 0x80+0x10+6+8: __bufccpy ("res (hl), 3"); break;  
      case 0x80+0x10+7+8: __bufccpy ("res a, 3"); break;  
    
      case 0x80+0x20+0: __bufccpy ("res b, 4"); break;  
      case 0x80+0x20+1: __bufccpy ("res c, 4"); break;  
      case 0x80+0x20+2: __bufccpy ("res d, 4"); break;  
      case 0x80+0x20+3: __bufccpy ("res e, 4"); break;  
      case 0x80+0x20+4: __bufccpy ("res h, 4"); break;  
      case 0x80+0x20+5: __bufccpy ("res l, 4"); break;  
      case 0x80+0x20+6: __bufccpy ("res (hl), 4"); break;  
      case 0x80+0x20+7: __bufccpy ("res a, 4"); break;  
      case 0x80+0x20+0+8: __bufccpy ("res b, 5"); break;  
      case 0x80+0x20+1+8: __bufccpy ("res c, 5"); break;  
      case 0x80+0x20+2+8: __bufccpy ("res d, 5"); break;  
      case 0x80+0x20+3+8: __bufccpy ("res e, 5"); break;  
      case 0x80+0x20+4+8: __bufccpy ("res h, 5"); break;  
      case 0x80+0x20+5+8: __bufccpy ("res l, 5"); break;  
      case 0x80+0x20+6+8: __bufccpy ("res (hl), 5"); break;  
      case 0x80+0x20+7+8: __bufccpy ("res a, 5"); break;  
    
      case 0x80+0x30+0: __bufccpy ("sres b, 6"); break;  
      case 0x80+0x30+1: __bufccpy ("sres c, 6"); break;  
      case 0x80+0x30+2: __bufccpy ("sres d, 6"); break;  
      case 0x80+0x30+3: __bufccpy ("sres e, 6"); break;  
      case 0x80+0x30+4: __bufccpy ("sres h, 6"); break;  
      case 0x80+0x30+5: __bufccpy ("sres l, 6"); break;  
      case 0x80+0x30+6: __bufccpy ("sres (hl), 6"); break;  
      case 0x80+0x30+7: __bufccpy ("sres a, 6"); break;  
      case 0x80+0x30+0+8: __bufccpy ("res b, 7"); break;  
      case 0x80+0x30+1+8: __bufccpy ("res c, 7"); break;  
      case 0x80+0x30+2+8: __bufccpy ("res d, 7"); break;  
      case 0x80+0x30+3+8: __bufccpy ("res e, 7"); break;  
      case 0x80+0x30+4+8: __bufccpy ("res h, 7"); break;  
      case 0x80+0x30+5+8: __bufccpy ("res l, 7"); break;  
      case 0x80+0x30+6+8: __bufccpy ("res (hl), 7"); break;  
      case 0x80+0x30+7+8: __bufccpy ("res a, 7"); break; 

      case 0xC0+0x00+0: __bufccpy ("set b, 0"); break;  
      case 0xC0+0x00+1: __bufccpy ("set c, 0"); break;  
      case 0xC0+0x00+2: __bufccpy ("set d, 0"); break;  
      case 0xC0+0x00+3: __bufccpy ("set e, 0"); break;  
      case 0xC0+0x00+4: __bufccpy ("set h, 0"); break;  
      case 0xC0+0x00+5: __bufccpy ("set l, 0"); break;  
      case 0xC0+0x00+6: __bufccpy ("set (hl), 0"); break;  
      case 0xC0+0x00+7: __bufccpy ("set a, 0"); break;  
      case 0xC0+0x00+0+8: __bufccpy ("set b, 1"); break;  
      case 0xC0+0x00+1+8: __bufccpy ("set c, 1"); break;  
      case 0xC0+0x00+2+8: __bufccpy ("set d, 1"); break;  
      case 0xC0+0x00+3+8: __bufccpy ("set e, 1"); break;  
      case 0xC0+0x00+4+8: __bufccpy ("set h, 1"); break;  
      case 0xC0+0x00+5+8: __bufccpy ("set l, 1"); break;  
      case 0xC0+0x00+6+8: __bufccpy ("set (hl), 1"); break;  
      case 0xC0+0x00+7+8: __bufccpy ("set a, 1"); break;  

      case 0xC0+0x10+0: __bufccpy ("set b, 2"); break;  
      case 0xC0+0x10+1: __bufccpy ("set c, 2"); break;  
      case 0xC0+0x10+2: __bufccpy ("set d, 2"); break;  
      case 0xC0+0x10+3: __bufccpy ("set e, 2"); break;  
      case 0xC0+0x10+4: __bufccpy ("set h, 2"); break;  
      case 0xC0+0x10+5: __bufccpy ("set l, 2"); break;  
      case 0xC0+0x10+6: __bufccpy ("set (hl), 2"); break;  
      case 0xC0+0x10+7: __bufccpy ("set a, 2"); break;  
      case 0xC0+0x10+0+8: __bufccpy ("set b, 3"); break;  
      case 0xC0+0x10+1+8: __bufccpy ("set c, 3"); break;  
      case 0xC0+0x10+2+8: __bufccpy ("set d, 3"); break;  
      case 0xC0+0x10+3+8: __bufccpy ("set e, 3"); break;  
      case 0xC0+0x10+4+8: __bufccpy ("set h, 3"); break;  
      case 0xC0+0x10+5+8: __bufccpy ("set l, 3"); break;  
      case 0xC0+0x10+6+8: __bufccpy ("set (hl), 3"); break;  
      case 0xC0+0x10+7+8: __bufccpy ("set a, 3"); break;  
    
      case 0xC0+0x20+0: __bufccpy ("set b, 4"); break;  
      case 0xC0+0x20+1: __bufccpy ("set c, 4"); break;  
      case 0xC0+0x20+2: __bufccpy ("set d, 4"); break;  
      case 0xC0+0x20+3: __bufccpy ("set e, 4"); break;  
      case 0xC0+0x20+4: __bufccpy ("set h, 4"); break;  
      case 0xC0+0x20+5: __bufccpy ("set l, 4"); break;  
      case 0xC0+0x20+6: __bufccpy ("set (hl), 4"); break;  
      case 0xC0+0x20+7: __bufccpy ("set a, 4"); break;  
      case 0xC0+0x20+0+8: __bufccpy ("set b, 5"); break;  
      case 0xC0+0x20+1+8: __bufccpy ("set c, 5"); break;  
      case 0xC0+0x20+2+8: __bufccpy ("set d, 5"); break;  
      case 0xC0+0x20+3+8: __bufccpy ("set e, 5"); break;  
      case 0xC0+0x20+4+8: __bufccpy ("set h, 5"); break;  
      case 0xC0+0x20+5+8: __bufccpy ("set l, 5"); break;  
      case 0xC0+0x20+6+8: __bufccpy ("set (hl), 5"); break;  
      case 0xC0+0x20+7+8: __bufccpy ("set a, 5"); break;  
    
      case 0xC0+0x30+0: __bufccpy ("set b, 6"); break;  
      case 0xC0+0x30+1: __bufccpy ("set c, 6"); break;  
      case 0xC0+0x30+2: __bufccpy ("set d, 6"); break;  
      case 0xC0+0x30+3: __bufccpy ("set e, 6"); break;  
      case 0xC0+0x30+4: __bufccpy ("set h, 6"); break;  
      case 0xC0+0x30+5: __bufccpy ("set l, 6"); break;  
      case 0xC0+0x30+6: __bufccpy ("set (hl), 6"); break;  
      case 0xC0+0x30+7: __bufccpy ("set a, 6"); break;  
      case 0xC0+0x30+0+8: __bufccpy ("set b, 7"); break;  
      case 0xC0+0x30+1+8: __bufccpy ("set c, 7"); break;  
      case 0xC0+0x30+2+8: __bufccpy ("set d, 7"); break;  
      case 0xC0+0x30+3+8: __bufccpy ("set e, 7"); break;  
      case 0xC0+0x30+4+8: __bufccpy ("set h, 7"); break;  
      case 0xC0+0x30+5+8: __bufccpy ("set l, 7"); break;  
      case 0xC0+0x30+6+8: __bufccpy ("set (hl), 7"); break;  
      case 0xC0+0x30+7+8: __bufccpy ("set a, 7"); break; 
      default: 
        assert (0);
      }
      break;
    default: 
      assert (0);
    }
    isec->addr = addrcount + g_addrb;
    isec->instr_len = cpu_lens[opcode];
    isec->opcode[0] = opcode;
    isec->opcode[1] = opcode2;
    addrcount += cpu_lens[opcode];
    list_insert (bankdis->instr_list, -1, isec);
  }
  return 0;
}

int lr35902_bankout (FILE *output /* offset setted */, struct bank_disassembler *bankdis, int bankid) {

  /* set attach */
  struct list_v *p;
  ks_int id;

  LIST_FOREACH (bankdis->armark_list, id, p) {
    struct addrmark *mk = (struct addrmark *) p->obj;
    struct list_v *p2;
    ks_int id2;
    LIST_FOREACH (bankdis->instr_list, id2, p2) {
      struct instr_sec *is  = (struct instr_sec *) p2->obj;
      if (is->addr >= mk->baddr) {
        if (is->addr == mk->baddr)
          is->attach = mk;
        break;
      }
    }
  }
  /* output distext */
  fprintf (output, "================ BANK %d Start ================ \n", bankid);
  LIST_FOREACH (bankdis->instr_list, id, p) {
    struct instr_sec *is  = (struct instr_sec *) p->obj;
    struct addrmark_n *amn;
    struct list_v *p2;
    ks_int id2;
    if (is->attach != ks_null) {
      /* out ref list */
      if (is->attach->refcall_tracker != ks_null && is->attach->refcall_tracker->nums > 0) {
        fprintf (output, "%%%d:%04x sub_%04x: ", bankid, is->addr, is->addr);
        LIST_FOREACH (is->attach->refcall_tracker, id2, p2) {
          amn = (struct addrmark_n *) p2->obj;
          if (amn->ccbranch != ks_false) 
            fprintf (output, "$%%%04x ", amn->addr);
          else 
            fprintf (output, ">%%%04x ", amn->addr);
        }
        fprintf (output, "\n");
      }
      if (is->attach->reflong_tracker != ks_null && is->attach->reflong_tracker->nums > 0) {
        fprintf (output, "%%%d:%04x long_%04x: ", bankid, is->addr, is->addr);
        LIST_FOREACH (is->attach->reflong_tracker, id2, p2) {
          amn = (struct addrmark_n *) p2->obj;
          if (amn->ccbranch != ks_false) 
            fprintf (output, "$%%%04x ", amn->addr);
          else 
            fprintf (output, ">%%%04x ", amn->addr);
        }
        fprintf (output, "\n");
      }
      if (is->attach->refshort_tracker != ks_null && is->attach->refshort_tracker->nums > 0) {
        fprintf (output, "%%%d:%04x loc_%04x: ", bankid, is->addr, is->addr);
        LIST_FOREACH (is->attach->refshort_tracker, id2, p2) {
          amn = (struct addrmark_n *) p2->obj;
          if (amn->ccbranch != ks_false) 
            fprintf (output, "$%%%04x ", amn->addr);
          else 
            fprintf (output, ">%%%04x ", amn->addr);
        }
        fprintf (output, "\n");
      }
    }
# if 0
    fprintf (output, "%%%04x %02x ", is->addr, is->opcode[0]);
    if (is->instr_len == 2)
      fprintf (output, "%02x ", is->opcode[1]);
    fprintf (output, "%s \n", is->opdesc);
#else
    fprintf (output, "%%%d:%04x ", bankid, is->addr);
    fprintf (output, "                %s \n", is->opdesc);
#endif 
  }
  fprintf (output, "================ BANK %d End ==================\n", bankid);
  return 0;
}

int 
lr35902_disassembler2 (host_char *path_r, host_char *path_w) {

  struct bank_disassembler bkdis;
  struct romheader *prh;
  int sig = -1;
  FILE *output = ks_null;
  ks_int promsize;
  ks_int sramsize;
  ks_int id;
  ks_uint8 *buf = ks_null;
  ks_int32 fsize = -1;
  ks_bool sgb_done, dmg_done, cgb_done;
  char cac;
  char title16[17];
  char title15[16];
  char title11[12];
  char *ctype = "no adapter";
  char *lic = "no adapter";
  
  static ks_uint8 nintendo_magicnumber[] =
  { 0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
    0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
    0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E };

# if defined (_WIN32)
  HANDLE win32fd = INVALID_HANDLE_VALUE;
  HANDLE win32mmap = INVALID_HANDLE_VALUE;
  DWORD dwCalcLow,dwCalcHigh;
# endif 

# if defined (_WIN32)
  if ( (win32fd = CreateFile (  path_r, 
                      GENERIC_READ, /*source only read */
                      FILE_SHARE_READ,  
                      NULL,       
                      OPEN_EXISTING, 
                      FILE_ATTRIBUTE_READONLY,     
                      NULL )) == INVALID_HANDLE_VALUE)
    return -1;
  if ((dwCalcLow = GetFileSize (win32fd, & dwCalcHigh)) <= 0x4000) {
    CloseHandle (win32fd);
    return -1;
  } 
  win32mmap = CreateFileMappingW 
       ( win32fd, NULL, PAGE_READONLY, 
          dwCalcHigh,      
          dwCalcLow,   
          NULL );
  assert (win32mmap != INVALID_HANDLE_VALUE);
  buf = (ks_uint8 *)MapViewOfFile (win32mmap, FILE_MAP_READ, 0, 0, 0); 
  assert (buf != NULL);
  prh = (struct romheader *)& buf[0x134];
  if (memcmp (& buf[0x104], 
                nintendo_magicnumber, sizeof (nintendo_magicnumber) != 0))
    goto __cleanup;
  else ;

  switch (prh->promsize) {
  case 0x00: promsize = 2; break;
  case 0x01: promsize = 4; break;
  case 0x02: promsize = 8; break;
  case 0x03: promsize =16; break;
  case 0x04: promsize =32; break;
  case 0x05: promsize =64; break;
  case 0x06: promsize =128; break;
  case 0x07: promsize =256; break;
  case 0x08: promsize =512; break;
  case 0x52: promsize =72; break;
  case 0x53: promsize =80; break;
  case 0x54: promsize =96; break;
  default : goto __cleanup;
  }

  if (dwCalcLow != (0x4000 * promsize))
    promsize = dwCalcLow/ 0x4000;
  else ;

#ifdef UCS2
  output = _wfopen (path_w,  L"wb");
#else 
  output = fopen (path_w,  "wb"));
#endif 
  if (output == NULL)
    goto __cleanup;
  else ;
  memset (title16, 0, sizeof (title16));
  memset (title15, 0, sizeof (title15));
  memset (title11, 0, sizeof (title11));

  /* get title */
  for (id = 0; id != 16; id++) {
    title16[id] = prh->title[id];
    title16[id] &= 0x7F;
    if (id < 15)
      title15[id] = title16[id];
    if (id < 11)
      title11[id] = title16[id];
  }
  /* assert cgb */
  cac = prh->title[15];
  if (cac & 0x80) {
    cgb_done = ks_true;
    if (cac & 0x40) 
      dmg_done = ks_false;
    else 
      dmg_done = ks_true;
  } else {
    cgb_done = ks_false;
    dmg_done = ks_true;
  }
  /* assert sgb */
  if (prh->sgb == 3)
    sgb_done = ks_true;
  else 
    sgb_done = ks_false;
  /* 
   * get cart type */
  kinit ();
  ctype = g_lutctype[prh->ctype];
  if (prh->anclic == 0x33) {
    // new lic 
    char v[3];
    v[2] = 0;
    *((short *)v) = prh->curlic;
    lic = g_lutcurlic[atoi (v)];
  } else {
    lic = g_lutanclic[prh->anclic];
  }
  switch (prh->ramsize) {
  case 0x00: sramsize = 0; break;
  case 0x01: sramsize =-1; break; /* 2K */
  case 0x02: sramsize = 1; break;
  case 0x03: sramsize = 4; break;
  case 0x04: sramsize =16; break;
  case 0x05: sramsize = 8; break;
  default : goto __cleanup;
  }
  fprintf (output, 
   ">!\n"\
   "  KS3578:: GBZ80 Static Disassembler - moecmks\n"\
   "  |\n"\
   "  rominfos:\n"\
   "     \\.__ title16:%s\n"\
   "     \\.__ title15:%s\n"\
   "     \\.__ title11:%s\n"\
   "     \\.__ manufacturer code: %08X\n"\
   "     \\.__ cgbbyte: %02X\n"\
   "     \\.__ cartridge type:%s\n"\
   "     \\.__ licensee:%s\n"\
   "     \\.__ promsize:%d\n"\
   "     \\.__ ramsize:%d\n"\
   "     \\.__ target code:%s\n"\
   "     \\.__ dmg support:%s\n"\
   "     \\.__ cgb support:%s\n"\
   "     \\.__ sgb support:%s\n"\
   "     \\.__ markv:%02x\n"\
   "     \\.__ hdcrc:%02x\n"\
   "     \\.__ gcrc:%04x\n"\
   "  |____________________________________\n"\
   "!<\n\n",
   title16, /* title */
   title15, /* title */
   title11, /* title */
   *(unsigned int *)& title16[11],
   (unsigned char)prh->title[15],
   ctype,
   lic, /* licensee*/
   promsize,
   sramsize,
   (prh->targetcode == 0) ? "japanese" :"non-japanese",
   dmg_done ? "true" : "false",
   cgb_done ? "true" : "false",
   sgb_done ? "true" : "false",
   prh->maskver,
   prh->hdcrc,
   prh->gcrc);
   
  /* disbanlk */
  for (id = 0; id != promsize; id++ ){

    if (id == 0)
      g_addrb = 0;
    else 
      g_addrb = 0x4000;

    list_init (& bkdis.armark_list);
    list_init (& bkdis.instr_list);

    lr35902_getaddrmark ((char *)buf, id, bkdis.armark_list);
    lr35902_bankdis ((char *)buf, id, & bkdis);
    lr35902_bankout (output, & bkdis, id);
  }
__cleanup:
  if (buf != NULL) 
    UnmapViewOfFile (buf);
  if (win32mmap != NULL) 
    CloseHandle (win32mmap);
  if (win32fd != NULL) 
    CloseHandle (win32fd);
  if (output != NULL)
    fclose (output);
  return sig;


# endif 
  return sig;
}