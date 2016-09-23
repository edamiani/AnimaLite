#include "TestWindowSdl.h"

int main(int argc, char* args[])
{
	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Point2<AE::uint>(640, 480);
	windowDesc.position = AE::Math::Point2<AE::int32>(50, 50);

	AE::OS::Window *window = new AE::OS::WindowSdl("Test", windowDesc);

	window->show();

	while(true) {}

	return 0;
}