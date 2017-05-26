#include "stdafx.h"  //________________________________________ EjerciciosLista.cpp
#include "EjerciciosLista.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosLista app;
	return app.BeginDialog(IDI_EjerciciosLista, hInstance);
}

void EjerciciosLista::Window_Open(Win::Event& e)
{
	//________________________________________________________ lv1
	lv1.Cols.Add(0, LVCFMT_LEFT, 100, L"Par");
	lv1.Cols.Add(1, LVCFMT_RIGHT, 200, L"Impar");
	for (int i = 0; i <= 10; i++)
	{
		lv1.Items.Add(i, Sys::Convert::ToString(2 * i), 100 + i);
		lv1.Items[i][1].Text = Sys::Convert::ToString(2 * i + 1);
	}
}

void EjerciciosLista::lv1_ItemActivate(Win::Event& e)
{
	const int selectedIndex = lv1.GetSelectedIndex();
	if (selectedIndex < 0)return;
	this->Text = lv1.Items[selectedIndex][0].Text;
}

