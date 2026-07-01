/*
 * hmi_typedefs.hpp
 *
 *  Created on: Nov 10, 2023
 *      Author: jacobo.gonzalez
 */

#ifndef INC_NEXTION_HMI_CLASS_HMI_TYPEDEFS_HPP_
#define INC_NEXTION_HMI_CLASS_HMI_TYPEDEFS_HPP_
#include <map>
#include <stdint.h>
#include <string>

//here only define the struct for control of HMI for each object
//HMI
typedef struct{
	bool on_rst;
	bool startup;
	bool serialBufferOverflow;
	bool ae_sleep_mod;
	bool ready;
	bool upgrade;
	bool transparent_mod;
	bool instruccion_error;
	bool instruccion_succes;
	bool invalid_comp_ID;
	bool invalid_page;
	bool invalid_variable;
}Flags;

typedef struct{
	uint16_t xpos;
	uint16_t ypos;
	uint8_t  status;
}touch_screen;

typedef struct{
	//flags internal and control
	Flags			flags;
	//status
	uint8_t 		page;
	uint8_t 		brigth;
	uint8_t 		status;
	//touch_screen
	touch_screen	touch_awake;	//awake
	touch_screen	touch_sleep;	//sleep
	std::string 	rx_string;
	uint32_t 		read_num_data;
}HMI_STRUCT;

//Struct for botton
typedef struct{
	std::string	name;
	uint8_t 	page;
	uint8_t 	id;
	uint16_t 	colorText;
	uint16_t 	colorTextPress;
	uint16_t 	colorBackground;
	uint16_t 	colorBackgroundPress;
	uint16_t 	xpos;
	uint16_t	ypos;
	std::string	text;
	uint8_t 	xcen;
	uint8_t 	ycen;
	uint8_t 	spax;
	uint8_t 	spay;
	bool 		touch_event;
	bool 		isbr;

}HMI_BUTTON;

//text button
typedef struct{
	std::string name;
	uint8_t 	id;
	std::string text;
	uint8_t		page;
	uint16_t 	color;
	uint16_t 	colorBackground;
	uint8_t  	font;
	uint16_t 	xpos;
	uint16_t	ypos;
}HMI_TEXT;

//number
typedef struct{

	std::string name;
	uint8_t 	id;
	int 		value;
	uint8_t		page;
	uint16_t 	color;
	uint16_t 	colorBackground;
	uint8_t  	font;
	uint16_t 	xpos;
	uint16_t	ypos;
	uint8_t		format;
	uint8_t 	lenth;
	uint8_t 	spax;
	uint8_t 	spay;
	bool	 	isbr;
	bool 		touch_event;

}HMI_NUMBER;

enum class CommandEnum{

	drag=0,
	aph,
	effect,
	font,
	bco,
	bco1,
	bco2,
	pco,
	pco0,
	pco1,
	pco2,
	pco3,
	xcen,
	ycen,
	pw,
	txt,
	isbr,
	spax,
	spay,
	x,
	y,
	dir,
	dis,
	tim,
	en,
	val,
	lenth,
	format,
	vvs0,
	vvs1,
	vvs2,
	wid,
	hig,
	maxval,
	minval,
	ch,
	pic,
	picc,
	up,
	down,
	left,
	gdw,
	gdh
};

enum class EffectType{
	load=0,
	topflyinto,
	bottomflyinto,
	leftflyinto,
	rightflyinto,
	topleftflyinto,
	toprigthflyinto,
	bottomleftflyinto,
	bottomrigthflyinto
};

enum class DirType{
	left_to_rigth=0,
	rigth_to_left,
	up_to_down,
	down_to_up,

};

enum class FormatType{
	 decimal,
	 currency,
	 hex
};

std::string getCommand(CommandEnum command);


#endif /* INC_NEXTION_HMI_CLASS_HMI_TYPEDEFS_HPP_ */
