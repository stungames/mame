
#include "emu.h"

#include "drivenum.h"
GAME_EXTERN(___empty);
GAME_EXTERN(mk2);
GAME_EXTERN(mk2chal);
GAME_EXTERN(mk2r11);
GAME_EXTERN(mk2r14);
GAME_EXTERN(mk2r20);
GAME_EXTERN(mk2r21);
GAME_EXTERN(mk2r30);
GAME_EXTERN(mk2r31e);
GAME_EXTERN(mk2r32e);
GAME_EXTERN(mk2r42);
GAME_EXTERN(mk2r91);

game_driver const* const driver_list::s_drivers_sorted[12] =
{
	&GAME_NAME(___empty),
	&GAME_NAME(mk2),
	&GAME_NAME(mk2chal),
	&GAME_NAME(mk2r11),
	&GAME_NAME(mk2r14),
	&GAME_NAME(mk2r20),
	&GAME_NAME(mk2r21),
	&GAME_NAME(mk2r30),
	&GAME_NAME(mk2r31e),
	&GAME_NAME(mk2r32e),
	&GAME_NAME(mk2r42),
	&GAME_NAME(mk2r91),
};

std::size_t const driver_list::s_driver_count = 12;
