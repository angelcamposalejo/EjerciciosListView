#include "stdafx.h"  //________________________________________ EjerciciosLista.cpp
#include "EjerciciosLista.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	EjerciciosLista app;
	return app.BeginDialog(IDI_EjerciciosLista, hInstance);
}

void EjerciciosLista::Window_Open(Win::Event& e)
{
	//Crear imagen list
	imageList.Create(32, 32, 2);
	imageList.AddIcon(this->hInstance, IDI_ICON1);
	imageList.AddIcon(this->hInstance, IDI_ICON2);
	//________________________________________________________ lv1
	lv1.SetImageList(imageList, true);
	lv1.Cols.Add(0, LVCFMT_LEFT, 100, L"Número");
	for (int i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			lv1.Items.Add(i-1,0,Sys::Convert::ToString(i));
		}
		else
		{
			lv1.Items.Add(i - 1, 1, Sys::Convert::ToString(i));
		}
	}
}

void EjerciciosLista::lv1_ItemActivate(Win::Event& e)
{
	const int selectedIndex = lv1.GetSelectedIndex();
	if (selectedIndex < 0)return;
	this->Text = lv1.Items[selectedIndex][0].Text;
}

