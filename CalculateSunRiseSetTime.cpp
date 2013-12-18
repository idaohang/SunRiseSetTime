// CalculateSunRiseSetTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"

int _tmain(int argc, _TCHAR* argv[])
{
	const double	jdConst		= 2451545.0009;
	const DWORD		jdwConst		= 2451545;
	DWORD			jDate		= 352;
	double			lw			= 0.0;
	DWORD			jCycle		= 13;			//	TODO:

	//	Approximate Solar Noon
	double			j			= jdConst + lw/360 + jCycle;
	//	Solar Mean Anomaly
	double			m			= (357.5291 + 0.98560028 * (j - jdwConst));
					m			= m - ((int)m - (int)m%360);
	//	Equation of Center
	double			c			= 1.9148 * sin(m) + 0.02 * sin(2*m) + 0.0003 * sin(3*m);
	//	Ecliptic Logitude
	double			el			= m + 102.9372 + c + 180;
					el			= el - ((int)el - (int)el%360);
	//	Solar Transit
	double			jTransit	= j + 0.0053 * sin(m) - 0.0069 + sin(2 * el);
	//	Declination of the Sun
	double			d			= asin(sin(el) * sin(23.45));
	//	Hour Angle
	double			ln			= 0.0;
	double			ha			= acos( (sin(-0.83) - sin(ln)*sin(d))/(cos(ln)*cos(d)) );
	//	Elevation-of-Observer Correction
	double			h			= 0.0;
	double			ec			= -2.076 * sqrt(h)/60;

	//	Julian Date of Sun Rise/Set
	double			jSet		= jdConst + (ha+lw) / 360 + n + 0.0053 * sin(m) - 0.0069 * sin(2 * el);
	double			jRise		= jTransit - (jSet - jTransit);


	//	Hour Angle of Sun Rise/Set
	double latitude = 0.0;
	haSun =acos( -tan(latitude) * tan(d) )

	return 0;
}

