#include "gtest.h"
#include"../Polinom-List/List.h"
#include"../Polinom-List/List_Head.h"
#include"../Polinom-List/Polinom.h"	
TEST(TPolinom, can_craete_polinom)
{
	ASSERT_NO_THROW(TPolinom p);

}
TEST(TPolinom, can_craete_polinom_zero)
{
	TPolinom p;
	EXPECT_EQ(1, p.IsEmpty());

}
TEST(TPolinom, can_craete_monom)
{
	Monom m;
	EXPECT_EQ(0, m.coeff);
	EXPECT_EQ(0, m.px);
	EXPECT_EQ(0, m.py);
	EXPECT_EQ(0, m.pz);
}
TEST(TPolinom, can_craete_polinom_throw_monom)
{
	int **mas;
	int size = 2;
	mas = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		mas[i] = new int[2];
	}

	mas[0][0] = 3;
	mas[0][1] = 123;
	mas[1][0] = 1;
	mas[1][1] = 345;
	ASSERT_NO_THROW(TPolinom p(mas, size));
	TPolinom p(mas, size);
	p.Reset();
	EXPECT_EQ(1, p.GetMonom().coeff);
	EXPECT_EQ(3, p.GetMonom().px);
	EXPECT_EQ(4, p.GetMonom().py);
	EXPECT_EQ(5, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(3, p.GetMonom().coeff);
	EXPECT_EQ(1, p.GetMonom().px);
	EXPECT_EQ(2, p.GetMonom().py);
	EXPECT_EQ(3, p.GetMonom().pz);
}
TEST(TPolinom, can_not_craete_monom)
{
	ASSERT_ANY_THROW(Monom m(1,-1,2,3));
	
}
TEST(TPolinom, can_equally_2polinom)
{
	int **mas;
	int size = 2;
	mas = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		mas[i] = new int[2];
	}

	mas[0][0] = 3;
	mas[0][1] = 123;
	mas[1][0] = 1;
	mas[1][1] = 345;
	TPolinom p1(mas,size), p2;
	ASSERT_NO_THROW(p2=p1);
	p2 = p1;
	p2.Reset();
	EXPECT_EQ(1, p2.GetMonom().coeff);
	EXPECT_EQ(3, p2.GetMonom().px);
	EXPECT_EQ(4, p2.GetMonom().py);
	EXPECT_EQ(5, p2.GetMonom().pz);
	p2.GoNext();
	EXPECT_EQ(3, p2.GetMonom().coeff);
	EXPECT_EQ(1, p2.GetMonom().px);
	EXPECT_EQ(2, p2.GetMonom().py);
	EXPECT_EQ(3, p2.GetMonom().pz);
}
TEST(TPolinom, can_mult)
{
	int **mas;
	int size = 2;
	mas = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		mas[i] = new int[2];
	}

	mas[0][0] = 3;
	mas[0][1] = 123;
	mas[1][0] = 1;
	mas[1][1] = 345;
	
	TPolinom p(mas, size);
	double k = 2;
	ASSERT_NO_THROW(p *= k);
	p.Reset();
	EXPECT_EQ(2,p.GetMonom().coeff);
	p.GoNext();
	EXPECT_EQ(6, p.GetMonom().coeff);
}
TEST(TPolinom, can_mult_on_monom)
{
	int **mas;
	int size = 2;
	mas = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		mas[i] = new int[2];
	}

	mas[0][0] = 3;
	mas[0][1] = 123;
	mas[1][0] = 1;
	mas[1][1] = 345;
	Monom m(2, 1, 5, 6);
	TPolinom p(mas, size);
	ASSERT_NO_THROW(p *= m);
	p.Reset();
	EXPECT_EQ(2, p.GetMonom().coeff);
	EXPECT_EQ(4, p.GetMonom().px);
	EXPECT_EQ(9, p.GetMonom().py);
	EXPECT_EQ(11, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(6, p.GetMonom().coeff);
	EXPECT_EQ(2, p.GetMonom().px);
	EXPECT_EQ(7, p.GetMonom().py);
	EXPECT_EQ(9, p.GetMonom().pz);
}
TEST(TPolinom, can_add_monom)
{
	int **mas;
	int size = 2;
	mas = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		mas[i] = new int[2];
	}

	mas[0][0] = 3;
	mas[0][1] = 123;
	mas[1][0] = 1;
	mas[1][1] = 345;
	Monom m(2, 1, 5, 6);
	TPolinom p(mas, size);
	ASSERT_NO_THROW(p.InsMonom(m));
	cout << "p=" << p << endl;

}
TEST(TPolinom, can_add_polinom_and_destroy_First)
{
	int **mas1, **mas2;
	int size =2 ;
	mas1 = new int*[2];
	for (int i = 0; i < size; i++)
	{
		mas1[i] = new int[size];
	}

	mas1[0][0] = 1;
	mas1[0][1] = 111;
	mas1[1][0] = 3;
	mas1[1][1] = 333;
	TPolinom p(mas1, size);
	mas2 = new int*[size];
	for (int i = 0; i < size; i++)
	{
		mas2[i] = new int[size];
	}

	mas2[0][0] = 2;
	mas2[0][1] = 222;
	mas2[1][0] = -3;
	mas2[1][1] = 333;
	TPolinom q(mas2, size);
	ASSERT_NO_THROW(p += q);
	p.Reset();
	EXPECT_EQ(2, p.GetMonom().coeff);
	EXPECT_EQ(2, p.GetMonom().px);
	EXPECT_EQ(2, p.GetMonom().py);
	EXPECT_EQ(2, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(1, p.GetMonom().coeff);
	EXPECT_EQ(1, p.GetMonom().px);
	EXPECT_EQ(1, p.GetMonom().py);
	EXPECT_EQ(1, p.GetMonom().pz);

}
TEST(TPolinom, can_add_polinom_and_destroy_medium)
{
	int **mas1, **mas2;
	int size = 3;
	mas1 = new int*[2];
	for (int i = 0; i < size; i++)
	{
		mas1[i] = new int[size];
	}

	mas1[0][0] = 1;
	mas1[0][1] = 111;
	mas1[1][0] = 3;
	mas1[1][1] = 333;
	mas1[2][0] = 2;
	mas1[2][1] = 222;
	TPolinom p(mas1, size);
	mas2 = new int*[2];
	for (int i = 0; i < size; i++)
	{
		mas2[i] = new int[size];
	}

	mas2[0][0] = -2;
	mas2[0][1] = 222;
	mas2[1][0] = 3;
	mas2[1][1] = 313;
	mas2[2][0] = 4;
	mas2[2][1] = 201;
	TPolinom q(mas2, size);
	ASSERT_NO_THROW(p += q);
	p.Reset();
	EXPECT_EQ(3, p.GetMonom().coeff);
	EXPECT_EQ(3, p.GetMonom().px);
	EXPECT_EQ(3, p.GetMonom().py);
	EXPECT_EQ(3, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(3, p.GetMonom().coeff);
	EXPECT_EQ(3, p.GetMonom().px);
	EXPECT_EQ(1, p.GetMonom().py);
	EXPECT_EQ(3, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(4, p.GetMonom().coeff);
	EXPECT_EQ(2, p.GetMonom().px);
	EXPECT_EQ(0, p.GetMonom().py);
	EXPECT_EQ(1, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(1, p.GetMonom().coeff);
	EXPECT_EQ(1, p.GetMonom().px);
	EXPECT_EQ(1, p.GetMonom().py);
	EXPECT_EQ(1, p.GetMonom().pz);
}TEST(TPolinom, can_add_polinom_and_destroy_last)
{
	int **mas1, **mas2;
	int size = 3;
	mas1 = new int*[2];
	for (int i = 0; i < size; i++)
	{
		mas1[i] = new int[size];
	}

	mas1[0][0] = 1;
	mas1[0][1] = 111;
	mas1[1][0] = 3;
	mas1[1][1] = 333;
	mas1[2][0] = 2;
	mas1[2][1] = 222;
	TPolinom p(mas1, size);
	mas2 = new int*[2];
	for (int i = 0; i < size; i++)
	{
		mas2[i] = new int[size];
	}

	mas2[0][0] = -1;
	mas2[0][1] = 111;
	mas2[1][0] = 3;
	mas2[1][1] = 313;
	mas2[2][0] = 4;
	mas2[2][1] = 201;
	TPolinom q(mas2, size);
	ASSERT_NO_THROW(p += q);
	p.Reset();
	EXPECT_EQ(3, p.GetMonom().coeff);
	EXPECT_EQ(3, p.GetMonom().px);
	EXPECT_EQ(3, p.GetMonom().py);
	EXPECT_EQ(3, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(3, p.GetMonom().coeff);
	EXPECT_EQ(3, p.GetMonom().px);
	EXPECT_EQ(1, p.GetMonom().py);
	EXPECT_EQ(3, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(2, p.GetMonom().coeff);
	EXPECT_EQ(2, p.GetMonom().px);
	EXPECT_EQ(2, p.GetMonom().py);
	EXPECT_EQ(2, p.GetMonom().pz);
	p.GoNext();
	EXPECT_EQ(4, p.GetMonom().coeff);
	EXPECT_EQ(2, p.GetMonom().px);
	EXPECT_EQ(0, p.GetMonom().py);
	EXPECT_EQ(1, p.GetMonom().pz);
}
TEST(TPolinom, can_craete_monom_n)
{
	Monom m(1,2,3,4);
	EXPECT_EQ(1, m.coeff);
	EXPECT_EQ(2, m.px);
	EXPECT_EQ(3, m.py);
	EXPECT_EQ(4, m.pz);
	system("pause");
}
