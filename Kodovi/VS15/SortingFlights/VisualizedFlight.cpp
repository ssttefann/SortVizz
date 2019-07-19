#include "VisualizedFlight.h"


VisualizedFlight::VisualizedFlight(Flight f, int sor, int unsor,int num):
	flight(f),sortedIndex(sor),unsortedIndex(unsor), numOfFlightsTotal(num),
	Fl_Widget(120 + unsor * (500/num +1+ 50/num), 50 + 250 - 250/num * (sor + 1), 500 / num , (250/num) * (sor + 1))  //matematika bajo moj
{
	
}

VisualizedFlight::VisualizedFlight(Flight f, int sor, int unsor) :
	flight(f), sortedIndex(sor), unsortedIndex(unsor),numOfFlightsTotal(10),
	Fl_Widget(100 + unsor * 55, 50 + 250 - 25 * (sor + 1), 50, 25 * (sor + 1))
{

}


VisualizedFlight::VisualizedFlight(const VisualizedFlight & vf):
	Fl_Widget(100 + vf.unsortedIndex * 55, 50 + 250 - 25 * (vf.sortedIndex + 1), 50, 25 * (vf.sortedIndex + 1), ""),
	flight(vf.flight),
	sortedIndex(vf.sortedIndex),
	unsortedIndex(vf.unsortedIndex),
	numOfFlightsTotal(vf.numOfFlightsTotal)
{

}



void VisualizedFlight::draw()
{

	fl_color(boja); 
	fl_rectf(x(), y(), w(), h());    // rectangle as background                
	if (label()) {                                // any label assigned?
		fl_font(labelfont(), labelsize());          // set font/size
		fl_color(labelcolor());                     // set color
		fl_draw(label(), x(), y(), w(), h(), align()); // draw text over image and background
	}
}



void VisualizedFlight::write(const char * s)
	//writes text inside the widget
{
	fl_color(FL_BLACK);
	fl_font(0, 14-numOfFlightsTotal/10);
	fl_draw(90, s, x()+280/ numOfFlightsTotal, y()+250/numOfFlightsTotal*(sortedIndex+1) -20/ numOfFlightsTotal);
	if (sortedIndex < 10) {
		fl_draw(0, std::to_string(sortedIndex+1).c_str(), x() + 190/ numOfFlightsTotal, y() + 250 / numOfFlightsTotal * (sortedIndex + 1) + 210/numOfFlightsTotal);
	}
	else {
		fl_draw(0, std::to_string(sortedIndex+1).c_str(), x() + 150/ numOfFlightsTotal, y() + 250 / numOfFlightsTotal * (sortedIndex + 1) + 210/ numOfFlightsTotal);
	}
	
	redraw();
}

void VisualizedFlight::move(int jean, int dva)
{
	position(x() + jean, y() + dva);
	draw();
}

bool VisualizedFlight::operator=(VisualizedFlight &vf)
{
	string s1 = flight.getFNumber();
	string s2 = vf.flight.getFNumber();

	return strcmp(vf.flight.getFNumber().c_str(),s1.c_str());
}


