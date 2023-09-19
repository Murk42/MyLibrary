#pragma once

namespace MyLibrary
{
	void InitializeLibrary();
	void DeinitializeLibrary();

	void* CreateWindow();
	void DestroyWindow(void* window);
}