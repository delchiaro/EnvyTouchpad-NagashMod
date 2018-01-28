#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

#include "frmPacketObserver.h"
#include "frmSettings.h"
#include "TouchPad.h"
#include "TouchPadEventListener.h"

using namespace Microsoft::Win32;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::ComponentModel;
using namespace System::Text;
using namespace System::IO;

namespace envyTouchPad 
{

ref class envyTouchPadApplicationContext : public ApplicationContext
{
public:
    envyTouchPadApplicationContext()
    {
        initializeConfigurations();
        initializeTouchPad();
        initializeTimer();
        
        Application::ApplicationExit += gcnew EventHandler( this, &envyTouchPadApplicationContext::OnApplicationExit );

        fPacketObserverForm = gcnew frmPacketObserver();
        fTouchPadEventListener->addPacketObserver(fPacketObserverForm);

        fSettingsForm = gcnew frmSettings(this, fConfigurations, fPacketObserverForm);
        fSettingsForm->Closed += gcnew EventHandler( this, &envyTouchPadApplicationContext::OnSettingsFormClosed );
        fSettingsForm->Closing += gcnew CancelEventHandler( this, &envyTouchPadApplicationContext::OnSettingsFormClosing );

        SystemEvents::PowerModeChanged += gcnew PowerModeChangedEventHandler( this, &envyTouchPadApplicationContext::OnPowerModeChanged );

        // debug console.
        //FreeConsole();
        //AllocConsole();
    }

    void OnApplicationExit( Object^ /*sender*/, EventArgs^ /*e*/ )
    {
        delete fTouchPad;
        if (fTouchPadEventListener != NULL)
        {
            delete fTouchPadEventListener;
        }
    }

private:
    void OnSettingsFormClosing( Object^ sender, CancelEventArgs^ /*e*/ )
    {
    }
    
    void OnSettingsFormClosed( Object^ /*sender*/, EventArgs^ /*e*/ )
    {
    }

    void OnPowerModeChanged(Object^ sender, PowerModeChangedEventArgs^ e)
    {
        // during power change events (sleep/resume), something happens
        // with the touchpad where events are no longer sent.
        // to handle this, startup a timer to keep
        // re-registering the event listener.
       startPowerModeChangedTimer();
    }

    void timedRegisterEventListener( Object^ /*myObject*/, EventArgs^ /*myEventArgs*/ )
    {
        fTouchPad->registerEventListener(fTouchPadEventListener);
        ++fNumberOfTimerTicks;

        if (fNumberOfTimerTicks == kMaxTimerTicks)
        {
            fTimer->Stop();
        }
    }

private:
    void initializeConfigurations()
    {
        ActionConfiguration^ actionConfiguration = gcnew ActionConfiguration();
        GeneralConfiguration^ generalConfiguration = gcnew GeneralConfiguration();
        ScrollConfiguration^ scrollConfiguration = gcnew ScrollConfiguration();
        TapConfiguration^ tapConfiguration = gcnew TapConfiguration();
        fConfigurations = gcnew Configurations
        (
            actionConfiguration,
            generalConfiguration,
            scrollConfiguration,
            tapConfiguration
        );

        if (!fConfigurations->load())
        {
            MessageBox::Show
            (
                "Failed to load configuration data!!  exiting...", 
                "Failed to load configuration data", 
                MessageBoxButtons::OK, 
                MessageBoxIcon::Error
            );
            ExitThread();
        }
    }

    void initializeTouchPad()
    {
        fTouchPadEventListener = NULL;
        fTouchPad = new TouchPad();

        if (!fTouchPad->isInitialized())
        {
            MessageBox::Show
            (
                "Unable to initialize TouchPad!  exiting...", 
                "Failed to initialize TouchPad", 
                MessageBoxButtons::OK, 
                MessageBoxIcon::Error
            );
            ExitThread();
        }

        fTouchPadEventListener = new TouchPadEventListener(fConfigurations, fTouchPad);
        if (!fTouchPad->registerEventListener(fTouchPadEventListener))
        {
            MessageBox::Show
            (
                "Unable to register TouchPad event listener!  exiting...", 
                "Failed to register event listener", 
                MessageBoxButtons::OK, 
                MessageBoxIcon::Error
            );
            ExitThread();
        }

        System::Text::StringBuilder^ errorMessageBuilder = gcnew System::Text::StringBuilder();
        if (!fTouchPad->isSetup(errorMessageBuilder))
        {
            MessageBox::Show
            (
                errorMessageBuilder->ToString(), 
                "Failed to setup TouchPad", 
                MessageBoxButtons::OK, 
                MessageBoxIcon::Error
            );
            ExitThread();
        }
    }

    void initializeTimer()
    {
        fNumberOfTimerTicks = 0;
        fTimer = gcnew System::Windows::Forms::Timer();
        fTimer->Interval = kTimerInterval;
        fTimer->Tick += gcnew EventHandler( this, &envyTouchPadApplicationContext::timedRegisterEventListener );
    }

    void startPowerModeChangedTimer()
    {
        fNumberOfTimerTicks = 0;
        fTimer->Start();
    }
private:
    Configurations^ fConfigurations;  
    int fNumberOfTimerTicks;
    frmPacketObserver^ fPacketObserverForm;
    frmSettings^ fSettingsForm;
    System::Windows::Forms::Timer^ fTimer;
    TouchPad* fTouchPad;
    TouchPadEventListener* fTouchPadEventListener;
   
    static const int kMaxTimerTicks = 25;
    static const int kTimerInterval = 500;
};

}