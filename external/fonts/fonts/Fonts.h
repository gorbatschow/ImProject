#pragma once

// Embedded mahi-gui fonts. The data for each font can be loaded by ImGui and NanoVG.
//
// ImGui::
//
// ImFontConfig font_cfg;
// font_cfg.FontDataOwnedByAtlas = false;
// ... more font_cfg params.
// ImGui::GetIO().Fonts->AddFontFromMemoryTTF(Roboto_Regular_ttf, Roboto_Regular_ttf_len, 14.0f,
// &font_cfg);
//
// NanoVG:
//
// nvgCreateFontMem(m_vg, "roboto", Roboto_Regular_ttf, Roboto_Regular_ttf_len, 0);
//
// Note that "RobotoMono_Bold_ttf", "fa_solid_900_ttf", and "fa_brands_400_ttf" are
// already loaded into ImGui by mahi-gui in Application.cpp, so don't duplicate them.
//
// The font data was generated with:
// Bash: xxd -i Roboto-Regular.ttf > font_data.txt

//==============================================================================
// ROBOTO
//==============================================================================

extern unsigned char Roboto_Regular_ttf[];
extern unsigned int  Roboto_Regular_ttf_len;

extern unsigned char Roboto_Bold_ttf[];
extern unsigned int  Roboto_Bold_ttf_len;

extern unsigned char Roboto_Italic_ttf[];
extern unsigned int  Roboto_Italic_ttf_len;

//==============================================================================
// ROBOTO MONO
//==============================================================================

extern unsigned char RobotoMono_Regular_ttf[];
extern unsigned int  RobotoMono_Regular_ttf_len;

extern unsigned char RobotoMono_Bold_ttf[];
extern unsigned int  RobotoMono_Bold_ttf_len;

extern unsigned char RobotoMono_Italic_ttf[];
extern unsigned int  RobotoMono_Italic_ttf_len;

