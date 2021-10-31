#pragma once
namespace matri
{
	class matrice
	{
	private:
		int col;
		int ligne;
		int** matrix;
	public:
		matrice(unsigned int colone =0 ,unsigned int ligne =0);
		matrice& Remplissage(float a);
		 matrice* operator+(const matrice& m)const;
		 matrice* operator*(const matrice& m)const;
		 matrice* operator-(const matrice& m);
		 void print(const matrice& m);
		 ~matrice();









	};

}