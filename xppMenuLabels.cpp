#include "xppMenuLabels.h"

/****************************************************************************************/
/*										Main window										*/
/****************************************************************************************/
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
	.Title		= "&File",
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
	.Dialogs	= {{.Title		= "New Curve",
					.EditLabels = {"X-Axis:",
								   "Y-Axis:",
								   "Z-Axis:",
								   "Color:",
								   "Line type:"},
					.CheckLabels ={},
					.SwitchLabels = {},
					.actionIndex = 0},
				   {.Title		= "Edit Curve",
					.EditLabels = {"Curve Id:"
								   "X-Axis:",
								   "Y-Axis:",
								   "Z-Axis:",
								   "Color:",
								   "Line type:"},
					.CheckLabels ={},
					.SwitchLabels = {},
					.actionIndex = 3},
				   {.Title		= "Postscript options",
					.EditLabels = {"Axes Fontsize:",
								   "Font:",
								   "Linewidth:"},
					.CheckLabels ={"Black/White (*) or Colored",
								   "Land (*)  or Port"},
					.SwitchLabels = {},
					.actionIndex = 4},
				   {.Title		= "Axes options",
					.EditLabels = {"X-Origin:",
								   "Y-Origin:",
								   "Z-Origin:"},
					.CheckLabels ={"Use X-origin:",
								   "Use Y-origin:",
								   "Use Z-origin:"},
					.SwitchLabels = {},
					.actionIndex = 7},
				   {.Title		= "Colormap",
					.EditLabels = {},
					.CheckLabels ={},
					.SwitchLabels = {"&Normal",
									 "&Periodic",
									 "&Hot",
									 "&Cool",
									 "&Blue-red",
									 "&Gray",
									 "C&ubehelix"},
					.actionIndex = 9}
	}
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
					.CheckLabels ={"Reset Storage",
								   "Use old ICs",
								   "Movie"},
					.SwitchLabels = {},
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
					.CheckLabels ={"Reset Storage",
								   "Use old ICs",
								   "Cycle Colors",
								   "Movie",
								   "Curve"},
					.SwitchLabels = {},
					.actionIndex = 1},
				   {.Title		= "New Initial Conditions",
					.EditLabels = {"TODO Parse ode file"},
					.CheckLabels ={},
					.SwitchLabels = {},
					.actionIndex = 7}
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
	.Dialogs	= {{.Title		= "Method",
					.EditLabels = {},
					.CheckLabels ={},
					.SwitchLabels = {"&Discrete",
									 "&Euler",
									 "&Modified Euler",
									 "&Runge Kutta",
									 "&Adams",
									 "&Gear",
									 "&Volterra",
									 "&Backwards Euler",
									 "&Qualst Runge Kuta",
									 "&Stiff",
									 "&CVode",
									 "Dormance Prince &5",
									 "Dormance Prince &83",
									 "Rosen &23",
									 "S&ymplectic"
					},
					.actionIndex = 7}
	}
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
	.Dialogs	= {{.Title		= "Choose torus",
					.EditLabels = {"Period"},
					.CheckLabels ={"TODO Read ode file"},
					.SwitchLabels = {},
					.actionIndex = 2}
	}
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
	.Dialogs	= {{.Title		= "Set Window range",
					.EditLabels = {"X min",
								   "X max",
								   "Y min",
								   "Y max"
					},
					.CheckLabels ={},
					.SwitchLabels = {},
					.actionIndex = 0}
	}
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
			BoundaryValues};
/****************************************************************************************/
/*										Auto window										*/
/****************************************************************************************/

xppMenu autoAxes= {
	.Title		= "&Axes",
	.Labels		= {"&Parameter",
				   "&Limits",
				   "P&lot type",
				   "&Zoom in",
				   "Zoom &out",
				   "Last &1 parameter",
				   "Last &2 parameter",
				   "&Fit",
				   "&Default",
				   "&Scroll"},
	.Dialogs	= {{.Title		= "Auto Plot Parameter",
					.EditLabels = {"Y-Axis",
								   "Main Parameter",
								   "Second Parameter"},
					.CheckLabels ={},
					.SwitchLabels = {},
					.actionIndex = 0},
				   {.Title		= "Auto Plot Limits",
					.EditLabels = {"X max",
								   "X min",
								   "Y max",
								   "Y min"},
					.CheckLabels ={},
					.SwitchLabels = {},
					.actionIndex = 1},
				   {.Title		= "Auto Plot Type",
					.EditLabels = {},
					.CheckLabels ={},
					.SwitchLabels = {"&High",
									 "&Norm",
									 "H&igh-Low",
									 "&Period",
									 "&Two Parameter",
									 "F&requency",
									 "&Average"},
					.actionIndex = 2}
	}
};

xppMenu autoClear= {
	.Title		= "&Clear",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu autoFile= {
	.Title		= "&File",
	.Labels		= {"&Import orbit",
				   "&Save diagram",
				   "&Load diagram",
				   "&Reset diagram",
				   "&Postscript",
				   "&SVG",
				   "&Clear grab",
				   "&Write points",
				   "&All info",
				   "Init &data",
				   "&Toggle redraw",
				   "Auto ra&nge",
				   "S&elect 2 parameter point",
				   "Draw la&bled",
				   "L&oad branch",
				   "&Quit"},
	.Dialogs	= {}
};

xppMenu autoGrab= {
	.Title		= "&Grab",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu autoNumerics= {
	.Title		= "&Numerics",
	.Labels		= {},
	.Dialogs	= {{.Title		= "Auto Parameter",
					.EditLabels = {"Ntst:",
								   "Nmax:",
								   "NPr:",
								   "Ds:",
								   "Dsmin:",
								   "Dsmax:",
								   "Ncol:",
								   "Parameter Min:",
								   "Parameter Max:",
								   "Norm Min:",
								   "Norm Max:",
								   "EPSL:",
								   "EPSU:",
								   "EPSS:",
								   "IAD:",
								   "MXBF:",
								   "IID:",
								   "ITMX:"
								   "ITNM:",
								   "NWTN:",
								   "IADS:"},
					.CheckLabels ={},
					.SwitchLabels = {},
					.actionIndex = 0}
	}
};

xppMenu autoParameter= {
	.Title		= "&Parameter",
	.Labels		= {},
	.Dialogs	= {{.Title		= "Auto Parameter",
					.EditLabels = {"Parameter 1:",
								   "Parameter 2:",
								   "TODO read ode file"},
					.CheckLabels  ={},
					.SwitchLabels = {},
					.actionIndex  = 0}
	}
};

xppMenu autoRedraw= {
	.Title		= "Re&draw",
	.Labels		= {},
	.Dialogs	= {}
};

xppMenu autoRun= {
	.Title		= "&Run",
	.Labels		= {},
	.Dialogs	= {}
};


xppMenu autoUserPeriod= {
	.Title		= "&User Period",
	.Labels		= {},
	.Dialogs	= {{.Title		= "Number",
					.EditLabels = {},
					.CheckLabels ={},
					.SwitchLabels = {"&1",
									 "&2",
									 "&3",
									 "&4",
									 "&5",
									 "&6",
									 "&7",
									 "&8",
									 "&9",},
					.actionIndex = 0}
	}
};

QList<xppMenu> autoMenus {	autoParameter,
							autoAxes,
							autoNumerics,
							autoRun,
							autoGrab,
							autoUserPeriod,
							autoClear,
							autoRedraw,
							autoFile
};
