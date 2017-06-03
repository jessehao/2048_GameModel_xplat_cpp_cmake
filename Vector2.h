#pragma once
class Vector2
{
public:
#pragma region Static Constants
	const static Vector2& UP;
	const static Vector2& DOWN;
	const static Vector2& LEFT;
	const static Vector2& RIGHT;
	const static Vector2& ZERO;
	const static Vector2& ONE;
#pragma endregion

#pragma region Variables
	double x;
	double y;
#pragma endregion

#pragma region Static Methods
	static double dot(const Vector2& vec1, const Vector2& vec2);
#pragma endregion

#pragma region Methods
	bool isVertical();
	bool isHorizontal();
	double getMagnitude();
	double getSqrMagnitude();
	Vector2* getNormalized();
	void normalize();
	void set(double x, double y);
	Vector2* getCopy();
#pragma endregion

#pragma region Operators
	bool operator==(const Vector2& vec);
	friend bool operator==(const Vector2& left, const Vector2& right);
	friend Vector2* operator-(const Vector2& left, const Vector2& right);
	friend Vector2* operator+(const Vector2& left, const Vector2& right);
	double operator[](int index);
	void operator+=(Vector2& vec);
	void operator-=(Vector2& vec);
#pragma endregion

#pragma region Constructor & Destructor
	Vector2();
	Vector2(const Vector2& vec);
	Vector2(const Vector2* vec);
	Vector2(double x, double y);
	~Vector2();
#pragma endregion
};

