/*
 *	Copyright (C) 2007-2009 Gabest
 *	http://www.gabest.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "stdafx.h"
#include "GSSetting.h"
#ifndef __linux__
#include "resource.h"
#endif

const char* dialog_message(int ID, bool* updateText) {
	if (updateText)
		*updateText = true;
	switch (ID)
	{
		case IDC_SKIPDRAWHACK:
		case IDC_SKIPDRAWHACKEDIT:
		case IDC_STATIC_SKIPDRAW:
			return "Skipdraw\n\nSkips drawing n surfaces completely. "
				"Use it, for example, to try and get rid of bad post processing effects."
				" Try values between 1 and 100.";
		case IDC_ALPHAHACK:
			return "Alpha Hack\n\nDifferent alpha handling. Can work around some shadow problems.";
		case IDC_OFFSETHACK:
			return "Halfpixel\n\nMight fix some misaligned fog, bloom, or blend effect.";
		case IDC_SPRITEHACK:
			return "Sprite Hack\n\nHelps getting rid of black inner lines in some filtered sprites."
				" Half option is the preferred one. Use it for Mana Khemia or Ar Tonelico for example."
				" Full can be used for Tales of Destiny.";
		case IDC_WILDHACK:
			return "WildArms\n\nLowers the GS precision to avoid gaps between pixels when"
				" upscaling. Full option fixes the text on WildArms games, while Half option might improve portraits"
				" in Ar Tonelico.\n\n"
				"Strech hack might work too";
		case IDC_MSAACB:
		case IDC_STATIC_MSAA:
			return "Multisample Anti-Aliasing\n\nEnables hardware Anti-Aliasing. Needs lots of memory."
				" The Z-24 modes might need to have LogarithmicZ to compensate for the bits lost (only in DX9 mode).";
		case IDC_AGGRESSIVECRC:
			return "Use more aggressive CRC hacks on some games\n\n"
				"Only affects few games, removing some effects which might make the image sharper/clearer.\n"
				"Affected games: FFX, FFX2, FFXII, GOW2, ICO, SoTC, SSX3.\n"
				"Works as a speedhack for: Steambot Chronicles.";
		case IDC_ALPHASTENCIL:
			return "Extend stencil based emulation of destination alpha to perform stencil operations while drawing.\n\n"
				"Improves many shadows which are normally overdrawn in parts, may affect other effects.\n"
				"Will disable partial transparency in some games or even prevent drawing some elements altogether.";
		case IDC_CHECK_NVIDIA_HACK:
			return "This is a hack to work around problems with recent NVIDIA drivers causing odd stretching problems in DirectX 11 only "
				"when using Upscaling.\n\n"
				"Try not to use this unless your game Videos or 2D screens are stretching outside the frame.\n\n"
				"If you have an AMD/ATi graphics card you should not need this.";
		case IDC_CHECK_DISABLE_ALL_HACKS:
			return "FOR TESTING ONLY!!\n\n"
				"Disable all CRC hacks - will break many games. Overrides CrcHacksExclusion at gsdx.ini\n"
				"\n"
				"It's possible to exclude CRC hacks also via the gsdx.ini. E.g.:\n"
				"CrcHacksExclusions=all\n"
				"CrcHacksExclusions=0x0F0C4A9C, 0x0EE5646B, 0x7ACF7E03";
		case IDC_ALIGN_SPRITE:
			return "Sprite Alignment Hack\n\n"
				"Fixes issues with upscaling(vertical lines) in Namco games like Ace Combat, Tekken, Soul Calibur, etc.";
		case IDC_STRETCH_SPRITE:
			return "Corrects the sampling of 2D sprite textures when upscaling.\n\n"
				"Fixes lines in sprites of games like Ar tonelico when upscaling.";
		case IDC_TCOFFSETX:
		case IDC_TCOFFSETX2:
		case IDC_STATIC_TCOFFSETX:
		case IDC_TCOFFSETY:
		case IDC_TCOFFSETY2:
		case IDC_STATIC_TCOFFSETY:
			return "Texture Coordinates Offset Hack\n\n"
				"Offset for the ST/UV texture coordinates. Fixes some odd texture issues and might fix some post processing alignment too.\n\n"
				"  0500 0500, fixes Persona 3 minimap, helps Haunting Ground.\n"
				"  0000 1000, fixes Xenosaga hair edges (DX10+ Issue)\n";

		default:
			if (updateText)
				*updateText = false;
			return "";
	}
	return "";
}
