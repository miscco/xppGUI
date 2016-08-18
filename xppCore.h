#ifndef XPPCORE_H
#define XPPCORE_H

#include <string>
#include <utility>
#include <vector>

#include <xppCoreDefines.h>

class xppCore
{
public:
	xppCore();

private:
	xppPlotWindow mainPlotWindow;
	xppPlotWindow autoPlotWindow;
};

#endif // XPPCORE_H
