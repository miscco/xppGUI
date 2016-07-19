#include "xppMenuLabels.h"

xppMenu BoundaryValues = {
	.Title		= "&Boundary values",
	.Labels		= {"&Range",
				   "&No show",
				   "&Show",
				   "&Periodic"},
	.Dialogs	= {}
};

xppMenu Continue = {
	.Title		= "&Continue",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu DirectionField = {
	.Title		= "&DirectionField",
	.Labels		= {"&Direction field",
				   "&Flow",
				   "&No direction field",
				   "&Colorize",
				   "Scaled direction field"},
	.Dialogs	= {}
};

xppMenu Erase = {
	.Title		= "&Erase",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu File = {
	.Title		= "&Fiele",
	.Labels		= {"&Printsource",
				   "&Write read",
				   "&Read set",
				   "&Auto",
				   "&Calculator",
				   "&Edit",
				   "&Save info",
				   "&Bell off",
				   "&Help",
				   "&Quit",
				   "&Transpose",
				   "T&ips",
				   "&Get parameter set",
				   "C&lone",
				   "Edit &Xprrc",
				   "T&utorial"},
	.Dialogs	= {}
};

xppMenu Graphics = {
	.Title		= "&Graphics",
	.Labels		= {"&Add Curve",
				   "&Delete last",
				   "&Remove all",
				   "&Edit curve",
				   "&Postscript",
				   "S&VG",
				   "&Freeze",
				   "A&xes options",
				   "Exp&ort data",
				   "&Colormap"},
	.Dialogs	= {}
};

xppMenu Integrate = {
	.Title		= "&Integrate",
	.Labels		= {"&Range",
				   "Range &2D",
				   "&Last",
				   "&Old",
				   "&Go",
				   "&Mouse",
				   "&Shift",
				   "&New",
				   "S&hoot",
				   "&File",
				   "Form&ula",
				   "M&ice",
				   "&DEA Guess",
				   "&Backward"},
	.Dialogs	= {{.Title		= "Range Integrate",
					.EditLabels = {"Range Over:",
								   "Steps:",
								   "Start:",
								   "End:"},
					.SwitchLabels ={"Reset Storage",
									"Use old ICs",
									"Movie"},
					.actionIndex = 0},
				   {.Title		= "Double Range Integrate",
									   .EditLabels = {"Range Over 1:",
													  "Start 1:",
													  "End 1:",
													  "Steps 1:",
													  "Range Over 2:",
													  "Start 2:",
													  "End 2:",
													  "Steps 2:"},
									   .SwitchLabels ={"Reset Storage",
													   "Use old ICs",
													   "Cycle Colors",
													   "Movie",
													   "Curve"},
									   .actionIndex = 1}
	}
};

xppMenu Kinescope = {
	.Title		= "&Kinescope",
	.Labels		= {"&Capture",
				   "&Reset",
				   "&Playback",
				   "&Autoplay",
				   "&Save",
				   "&Make Animation"},
	.Dialogs	= {}
};

xppMenu Nullclines = {
	.Title		= "&Nullclines",
	.Labels		= {"&New",
				   "&Restore",
				   "&Auto",
				   "&Manual",
				   "&Freeze",
				   "&Save"},
	.Dialogs	= {}
};

xppMenu Numerics = {
	.Title		= "N&umerics",
	.Labels		= {"&Total",
				   "&Start time",
				   "T&ransient",
				   "&Dt",
				   "&Nullcline control",
				   "&Singular point Controll",
				   "N&Output",
				   "&Method",
				   "D&elay",
				   "&Color code",
				   "&Stoc&hast",
				   "&Poincaré map",
				   "R&uelle plot",
				   "Loo&kup",
				   "Boundary &Values",
				   "&Averaging"},
	.Dialogs	= {}
};

xppMenu Parameter3D = {
	.Title		= "&3D Parameter",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu Parameters = {
	.Title		= "&Parameters",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu Phasespace = {
	.Title		= "Ph&asespace",
	.Labels		= {"&All",
				   "&None",
				   "&Choose"},
	.Dialogs	= {}
};

xppMenu Plot = {
	.Title		= "Plot &X vs t",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu Restore = {
	.Title		= "&Restore",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu Singular = {
	.Title		= "&Singular Points",
	.Labels		= {"&Go",
				   "&Mouse",
				   "&Range",
				   "Monte &Carlo"},
	.Dialogs	= {}
};

xppMenu Text = {
	.Title		= "&Text",
	.Labels		= {"&Text",
				   "&Arrow",
				   "&Pointer",
				   "&Marker",
				   "&Edit",
				   "&Delete all",
				   "Marker&s"},
	.Dialogs	= {}
};

xppMenu View = {
	.Title		= "&View",
	.Labels		= {"&2D",
				   "&3D",
				   "Array",
				   "&Toon"},
	.Dialogs	= {}
};

xppMenu Window = {
	.Title		= "&Window",
	.Labels		= {"&Create",
				   "&Kill all",
				   "&Destroy",
				   "&Bottom",
				   "&Auto",
				   "&Manual",
				   "&Simultaneous plot"},
	.Dialogs	= {}
};

QList<xppMenu> xppMenus {Integrate,
						Continue,
						Nullclines,
						DirectionField,
						Phasespace,
						Kinescope,
						Graphics,
						Numerics,
						File,
						Parameters,
						Erase,
						Window,
						Text,
						Singular,
						View,
						Plot,
						Restore,
						Parameter3D,
						BoundaryValues
};
