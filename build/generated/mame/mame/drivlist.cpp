#include "emu.h"

#include "drivenum.h"

GAME_EXTERN(___empty);
GAME_EXTERN(mk2);
GAME_EXTERN(mk3);
GAME_EXTERN(umk3);

game_driver const* const driver_list::s_drivers_sorted[4] =
{
	&GAME_NAME(___empty),
	&GAME_NAME(mk2),
	&GAME_NAME(mk3),
	&GAME_NAME(umk3),
};

std::size_t const driver_list::s_driver_count = 4;
