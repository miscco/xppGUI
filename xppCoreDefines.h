#ifndef XPPCOREDEFINES_H
#define XPPCOREDEFINES_H

#include <string>
#include <utility>
#include <vector>

typedef std::pair<double, double> dpair;
typedef std::vector<std::string>  stringList;

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

enum xppMethod {
	METHOD_DISCRETE = 0,
	METHOD_EULER,
	METHOD_MODEULER,
	METHOD_RK4,
	METHOD_ADAMS,
	METHOD_GEAR,
	METHOD_VOLTERRA,
	METHOD_BACKEUL,
	METHOD_RKQS,
	METHOD_STIFF,
	METHOD_CVODE,
	METHOD_DP5,
	METHOD_DP83,
	METHOD_RB23,
	METHOD_SYMPLECT,
	NUM_METHODS
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
	dpair xLim = std::make_pair( 0.0, 20.0);
	dpair yLim = std::make_pair(-5.0, 5.0);
	dpair zLim = std::make_pair(-5.0, 5.0);

	std::string xLabel = "time";
	std::string	yLabel = "";
	std::string	zLabel = "";

	bool xGrid		= false;
	bool xGridMinor	= false;
	bool yGrid		= false;
	bool yGridMinor	= false;
	bool zGrid		= false;
	bool zGridMinor	= false;
	bool useXOrigin	= false;
	bool useYOrigin	= false;
	bool useZOrigin	= false;

	double xOrigin  = 0.0;
	double yOrigin  = 0.0;
	double zOrigin  = 0.0;

	std::vector<xppPlotOptions> plotOptions;
};

struct xppAutoSettings {
	unsigned Ntst	= 50;
	unsigned Nmax	= 300;
	unsigned NPr	= 50;
	unsigned NCol	= 4;

	double	Ds		= 1E-3;

	dpair	DsRange   = std::make_pair(1E-5, 0.5);
	dpair	ParRange  = std::make_pair(0.0, 10.0);
	dpair	NormRange = std::make_pair(0.0, 1000);

	double	EPSL	= 1E-7;
	double	EPSU	= 1E-7;
	double	EPSS	= 1E-7;

	double	IAD		= 3;
	double	MXBF	= 5;
	double	IID		= 2;
	double	ITMX	= 8;
	double	ITNW	= 7;
	double	NWTN	= 3;
	double	IADS	= 1;

	xppColor stableEquilibriumColor	  = RED;
	xppColor unstableEquilibriumColor = BLACK;
	xppColor stablePeriodicColor	  = GREEN;
	xppColor unstablePeriodicColor	  = BLUE;

	xppPlotWindow autoPlotWindow;
};

struct xppMainSettings {
	bool quietMode	= false;
	bool useGradient= false;
	bool runNow		= false;
	bool simPlot	= false;
	bool is3D		= false;

	int seedRNG		= 0;
	int	numPlots	= 1;
	int numJump		= 1;
	int numMesh		= 40;
	int gridDF		= 10;
	int maxPointsVolt = 4000;

	double JAC_EPS  = 1E-5;
	double NEWT_TOL = 1E-5;
	double NEWT_ITER= 1E-5;

	double dt		= 0.05;
	double trans	= 0.0;

	stringList  xPlot = {""};
	stringList	yPlot = {""};
	stringList	zPlot = {""};

	std::vector<dpair> tLim = {std::make_pair( 0.0, 20.0)};
	std::vector<dpair> xLim = {std::make_pair( 0.0, 20.0)};
	std::vector<dpair> yLim = {std::make_pair(-5.0, 5.0)};
	std::vector<dpair> zLim = {std::make_pair(-5.0, 5.0)};

	std::string	logFile		= "";
	std::string outputFile  = "";
	std::string fontName	= "";
	std::string backImage	= "";

	xppColor stableManifoldColor	= BLACK;
	xppColor unstableManifoldColor	= BLACK;
	xppColor xNullclineColor		= BLACK;
	xppColor yNullclineColor		= BLACK;

	xppColorMap colorMap = C_NORM;

	xppLineStyle defaultLineStyle = lsLine;

	xppMethod method= METHOD_RK4;
	std::vector<dpair> dtLim = {std::make_pair( 0.0, 20.0)};

	xppPlotWindow mainPlotWindow;
};

#endif // XPPCOREDEFINES_H

