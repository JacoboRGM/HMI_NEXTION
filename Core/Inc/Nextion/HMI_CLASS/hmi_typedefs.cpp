/*
 * hmi_typedefs.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: jacobo.gonzalez
 */

#include "Nextion/HMI_CLASS/hmi_typedefs.hpp"

std::string getCommand(CommandEnum command){

	switch (command){

	case CommandEnum::drag:
		return "drag";
	case CommandEnum::aph:
		return "aph";
	case CommandEnum::effect:
		return "effect";
	case CommandEnum::font:
		return "font";
	case CommandEnum::bco:
		return "bco";
	case CommandEnum::bco1:
		return "bco1";
	case CommandEnum::bco2:
		return "bco2";
	case CommandEnum::pco:
		return "pco";
	case CommandEnum::pco0:
		return "pco0";
	case CommandEnum::pco1:
		return "pco1";
	case CommandEnum::pco2:
		return "pco2";
	case CommandEnum::pco3:
		return "pco3";
	case CommandEnum::xcen:
		return "xcen";
	case CommandEnum::ycen:
		return "ycen";
	case CommandEnum::pw:
		return "pw";
	case CommandEnum::txt:
		return "txt";
	case CommandEnum::isbr:
		return "isbr";
	case CommandEnum::spax:
		return "spax";
	case CommandEnum::spay:
		return "spay";
	case CommandEnum::x:
		return "x";
	case CommandEnum::y:
		return "y";
	case CommandEnum::dir:
		return "dir";
	case CommandEnum::dis:
		return "dis";
	case CommandEnum::tim:
		return "tim";
	case CommandEnum::en:
		return "en";
	case CommandEnum::val:
		return "val";
	case CommandEnum::lenth:
		return "lenth";
	case CommandEnum::format:
		return "format";
	case CommandEnum::vvs0:
		return "vvs0";
	case CommandEnum::vvs1:
		return "vvs1";
	case CommandEnum::vvs2:
		return "vvs2";
	case CommandEnum::wid:
		return "wid";
	case CommandEnum::hig:
		return "hig";
	case CommandEnum::maxval:
		return "maxval";
	case CommandEnum::minval:
		return "minval";
	case CommandEnum::ch:
		return "ch";
	case CommandEnum::pic:
		return "pic";
	case CommandEnum::picc:
			return "picc";
	case CommandEnum::up:
		return "up";
	case CommandEnum::down:
		return "down";
	case CommandEnum::left:
		return "left";
	case CommandEnum::gdw:
		return "gdw";
	case CommandEnum::gdh:
		return "gdh";
	};

	return "null";
}


