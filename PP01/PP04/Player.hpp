class Player
{
public:
	int x, y;
	Player()
	{
		x = 20;
		y = 7;
	}
	~Player()
	{

	}
	void isKeyPrssed()
	{
		y = 5;
	}
	void isKeyUnPressed()
	{
		y = 7;
	}
};
