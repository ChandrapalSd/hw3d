#include "App.h"

// TODO: make this less shitty
HWND global_hwnd = nullptr;

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow
	)
{
	static HWND global_hwnd = nullptr;
	try
	{
		return App{}.Go();
	}
	catch (const ChiliException& e)
	{
		MessageBox(global_hwnd, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(global_hwnd, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(global_hwnd, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}
