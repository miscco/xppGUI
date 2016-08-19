#ifndef XPPCOREDEFINES_H
#define XPPCOREDEFINES_H

#include <string>
#include <vector>

#include "xppColor.h"
#include "xppPlots.h"

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

struct xppAutoSettings {
	unsigned Ntst	= 50;
	unsigned Nmax	= 300;
	unsigned NPr	= 50;
	unsigned NCol	= 4;

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

	double	Ds		= 1E-3;
	double  DsMax	= 0.5;
	double	DsMin	= 1E-5;

	double  ParMax	= 10.0;
	double	ParMin	= 0.0;
	double  NormMax	= 1000.0;
	double	NormMin	= 0.0;

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

	double tmax     = 20.0;
	double tmin		= 0.0;
	double dtmax    = 20.0;
	double dtmin	= 0.0;

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

	xppPlotWindow mainPlotWindow;
};

#endif // XPPCOREDEFINES_H

