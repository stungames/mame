
#include "emu.h"

#include "drivenum.h"
GAME_EXTERN(___empty);
GAME_EXTERN(mk2);
GAME_EXTERN(sftm);

game_driver const* const driver_list::s_drivers_sorted[3] =
{
	&GAME_NAME(___empty),
	&GAME_NAME(mk2),
	&GAME_NAME(sftm),
};

std::size_t const driver_list::s_driver_count = 3;
