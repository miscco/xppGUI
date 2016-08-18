#ifndef XPPCOREDEFINES_H
#define XPPCOREDEFINES_H

#include <string>
#include <utility>
#include <vector>

enum xppColor {
	WHITE,
	RED,
	REDORANGE,
	ORANGE,
	YELLOWORANGE,
	YELLOW,
	YELLOWGREEN,
	GREEN,
	BLUEGREEN,
	BLUE,
	PURPLE,
	BLACK
};

enum xppColorMap {
	C_NORM,
	C_PERIODIC,
	C_HOT,
	C_COOL,
	C_REDBLUE,
	C_GRAY,
	C_CUBHLX
};

enum xppLineStyle {
	lsNone,
	lsLine,
	lsStepLeft,
	lsStepRight,
	lsStepCenter,
	lsImpulse
};

enum xppMarkerStyle {
	msNone,
	msDot,
	msCross,
	msPlus,
	msCircle,
	msDisc,
	msSquare,
	msDiamond,
	msStar,
	msTriangle,
	msTriangleInverted,
	msCrossSquare,
	msPlusSquare,
	msCrossCircle,
	msPlusCircle,
	msPeace
};

struct xppPlotOptions {
	xppLineStyle	lineStyle		= lsLine;
	double			lineWidth		= 1.0;
	xppMarkerStyle	markerStyle		= msCross;
	double			markerSize		= 1.0;

	xppColor		lineColor		= BLACK;
	xppColor		markerColor		= BLACK;
};

struct xppPlotWindow {
	std::pair<double, double> xLim = std::make_pair(-5.0, 5.0);
	std::pair<double, double> yLim = std::make_pair( 0.0, 5.0);
	std::pair<double, double> zLim = std::make_pair(-5.0, 5.0);

	std::string xLabel = "time";
	std::string	yLabel = "";
	std::string	zLabel = "";

	bool xGrid		= false;
	bool xGridMinor	= false;
	bool yGrid		= false;
	bool yGridMinor	= false;
	bool zGrid		= false;
	bool zGridMinor	= false;

	std::vector<xppPlotOptions> plotOptions;
};

#endif // XPPCOREDEFINES_H

