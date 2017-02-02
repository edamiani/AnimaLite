#include "TestWindowWxWidgets.h"

#include "Anima/Math/Vector2.h"

#include "Plugins/Graphics/Device/Sfml/ContextSfml.h"
#include "Plugins/Graphics/Device/Sfml/DriverSfml.h"
#include "Plugins/Graphics/Device/Sfml/ManagerSfml.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"

// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wx/event.h"
#include "wx/frame.h"
#include "wx/menu.h"
#include "wx/msgdlg.h"

#include <memory>

class MyFrame;

class MyApp : public wxApp
{
public:
	virtual bool OnInit();

	MyFrame *frame;
};

class MyWindow;

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	MyWindow *mWindow;
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

class MyWindow : public wxWindow
{
public:
	MyWindow(wxWindow *parent, wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize, long style = 0,
		const wxString& name = wxT("TestAnimaContext"))
		: wxWindow(parent, id, pos, size)
	{
		mDeviceManager = new AE::Graphics::Device::ManagerSfml();
		mDeviceManager->Install(AE::NO_OPTIONS);
		auto handle = GetHwnd();
		//auto handle = this->GetHandle();

		//AE::OS::WindowHandle handle = static_cast<AE::OS::WindowHandle>(this->GetHandle());
		AE::OS::WindowHandle windowHandle = handle;
		mWindow = std::unique_ptr<AE::OS::Window>(new AE::OS::WindowSdl(0, windowHandle));

		mWindow->SetPosition(AE::Math::Vector2(pos.x, pos.y));
		mWindow->SetDimensions(AE::Math::Vector2(size.x, size.y));
		
		deviceDriver = mDeviceManager->AcquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);
		deviceContext = deviceDriver->CreateDeviceContext(mWindow);
	}

	AE::Graphics::Device::Driver *deviceDriver;
	AE::Graphics::Device::Context *deviceContext;

private:
	void OnPaint(wxPaintEvent& event)
	{
		deviceContext->BeginRendering(AE::Graphics::Color(128, 0, 0, 255));

		deviceContext->EndRendering();
	}

	//void OnSize(wxSizeEvent& event);
	void OnEraseBackground(wxEraseEvent& event);
	
	void OnIdle(wxIdleEvent& event)
	{
		deviceContext->BeginRendering(AE::Graphics::Color(128, 0, 0, 255));

		deviceContext->EndRendering();


		/*auto handle = GetHwnd();
		mWindow = std::unique_ptr<AE::OS::Window>(new AE::OS::WindowSdl(0, &handle));

		mWindow->SetPosition(AE::Math::Vector2(GetPosition().x, GetPosition().y));
		mWindow->SetDimensions(AE::Math::Vector2(GetSize().x, GetSize().y));

		deviceDriver = mDeviceManager->AcquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);
		deviceContext = deviceDriver->CreateDeviceContext(mWindow);*/
	}

	AE::Graphics::Device::ManagerSfml *mDeviceManager;
	std::unique_ptr<AE::OS::Window> mWindow;

	wxDECLARE_EVENT_TABLE();
};

enum
{
	ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Hello, MyFrame::OnHello)
	EVT_MENU(wxID_EXIT, MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(MyWindow, wxWindow)
	EVT_PAINT(MyWindow::OnPaint)
wxEND_EVENT_TABLE()

//wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
	frame->Show(true);

	return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	/*mWindow = new MyWindow(this, wxID_ANY, wxDefaultPosition,
		wxSize(800, 600), wxSUNKEN_BORDER);*/
	mWindow = new MyWindow(this, wxID_ANY, wxDefaultPosition,
		wxDefaultSize, wxSUNKEN_BORDER);
	
	SetMenuBar(menuBar);
	
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
}

void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}


int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::Initialize();
	auto *windowManager = pluginManager->RegisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->Install(AE::NO_OPTIONS);

	MyApp* pApp = new MyApp();
	wxApp::SetInstance(pApp);
	wxEntryStart(argc, args);

	pApp->OnInit();

	pApp->OnRun();

	pApp->OnExit();

	return 0;
}