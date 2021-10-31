// Matrice.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "matrice.h"
#include  <iostream>
#include"assert.h"
using namespace std;
using namespace matri;
// TODO: This is an example of a library function

matri::matrice::matrice(unsigned int colone, unsigned int ligne)
{
	assert(colone!= 0 && ligne != 0);
	this->col = colone;
	this->ligne = ligne;
	this->matrix = new int*[this->ligne];
	for (int i = 0; i < ligne ; i++)
	{

		this->matrix[i] = new int[this->col];
		
	}
}

matrice& matri::matrice::Remplissage(float a)
{
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->matrix[i][j] = a;

		}

	}
	return *this;
	// TODO: insert return statement here
}

matrice* matri::matrice::operator+(const matrice& m) const
{
	{
		matrice* res = new matrice(this->col, this->ligne);
		for (int i = 0; i < this->ligne; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				res->matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];

			}

		}
		return res;
	}
}



matrice *matri::matrice::operator*(const matrice& m) const
{
	
	assert(this->col == m.ligne);
		matrice *newma = new matrice( this->col,this->ligne);
		for (int i = 0; i < newma->ligne; i++)
		{
			for (int j = 0; j < newma->col; j++)
			{
				newma->matrix[i][j] = 0;
				for (int k = 0; k < this->col; k++)
				{
					newma->matrix[i][j] += this->matrix[i][k] * m.matrix[k][i];
				}
			}
		}
		return newma;
	}



matrice* matri::matrice::operator-(const matrice& m)
{
	matrice* newma = new matrice(this->col, this->ligne);
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			newma->matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];

		}

	}
	return newma;
}

void matri::matrice::print(const matrice& m)
{
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			cout << "  "  << this->matrix[i][j] ;
		} 

		cout << "\n";
		}

	}


matri::matrice::~matrice()
{
	if (this->matrix != NULL)
	{
		delete this->matrix;
		this->matrix = NULL;
	}
  
}





