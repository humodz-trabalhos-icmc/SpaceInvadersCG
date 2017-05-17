class Shot {

public:
	//Shot(int shooter, double pos_x, double pos_y);
	void updatePos();
	void draw();
	void setPos(double x, double y);
	void setState(bool state)	{ this->state = state; }
	bool getState()				{ return state; }

private:
	bool state = false;
	int shooter;
	double pos_x;
	double pos_y;
};