#pragma once

#include "Configurations.h"
#include "EasingAlgorithm.h"
#include "frmPacketObserver.h"

namespace envyTouchPad 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class frmSettings : public System::Windows::Forms::Form
	{
	public:
		frmSettings
        (
            ApplicationContext^ parentAppContext, 
            Configurations^ configurations,
            frmPacketObserver^ packetObserverForm
        )
		{
			InitializeComponent();
            fParentAppContext = parentAppContext;
            fConfigurations = configurations;
            fPacketObserverForm = packetObserverForm;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmSettings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NotifyIcon^  notifyIcon;
	protected: 

	private: System::Windows::Forms::ContextMenuStrip^  ctxtNotifyIcon;
    private: System::Windows::Forms::ToolStripMenuItem^  mniExit;


	protected: 
	private: System::ComponentModel::IContainer^  components;
    private: System::Windows::Forms::ToolStripMenuItem^  mniSettings;
    private: System::Windows::Forms::TabControl^  tabSettings;
    private: System::Windows::Forms::TabPage^  tbpGeneral;
    private: System::Windows::Forms::TabPage^  tbpScrolling;
    private: System::Windows::Forms::TabPage^  tbpTapping;
    private: System::Windows::Forms::CheckBox^  chkStartWithWindows;
    private: System::Windows::Forms::TrackBar^  trackSingleTapIntervalThreshold;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  lblSingleTapIntervalThresholdValue;
    private: System::Windows::Forms::Label^  lblOneFinger;
    private: System::Windows::Forms::ComboBox^  cboOneFinger;
    private: System::Windows::Forms::ComboBox^  cboThreeFinger;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::ComboBox^  cboTwoFinger;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  lblSpeedValue;
    private: System::Windows::Forms::TrackBar^  trackSpeed;
    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::CheckBox^  chkAcceleration;
    private: System::Windows::Forms::Label^  lblAccelerationValue;

    private: System::Windows::Forms::TrackBar^  trackAcceleration;
    private: System::Windows::Forms::Label^  lblTapMaxDistanceValue;
    private: System::Windows::Forms::TrackBar^  trackTapMaxDistance;
    private: System::Windows::Forms::Label^  label6;
    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::ComboBox^  cboEasingAlgorithm;

    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Label^  lblInertialScrollDurationValue;
    private: System::Windows::Forms::TrackBar^  trackInertialScrollDuration;
    private: System::Windows::Forms::Label^  label8;
    private: System::Windows::Forms::Label^  lblTapMaxWThresholdValue;

    private: System::Windows::Forms::TrackBar^  trackTapMaxWThreshold;


    private: System::Windows::Forms::Label^  label9;
    private: System::Windows::Forms::Label^  lblTapMaxZThresholdValue;


    private: System::Windows::Forms::TrackBar^  trackTapMaxZThreshold;
    private: System::Windows::Forms::Label^  label10;
    private: System::Windows::Forms::Label^  lblScrollMaxZThresholdValue;
    private: System::Windows::Forms::TrackBar^  trackScrollMaxZThreshold;
    private: System::Windows::Forms::Label^  label11;
    private: System::Windows::Forms::Button^  btnApply;
    private: System::Windows::Forms::Button^  btnPacketObserver;
    private: System::Windows::Forms::Label^  lblDeltaRatioThresholdValue;
    private: System::Windows::Forms::TrackBar^  trackDeltaRatioThreshold;
    private: System::Windows::Forms::Label^  label12;
    private: System::Windows::Forms::TabPage^  tabActions;
    private: System::Windows::Forms::GroupBox^  groupBox2;
    private: System::Windows::Forms::ComboBox^  cboDown;
    private: System::Windows::Forms::Label^  label17;
    private: System::Windows::Forms::ComboBox^  cboUp;
    private: System::Windows::Forms::Label^  label16;
    private: System::Windows::Forms::ComboBox^  cboRight;
    private: System::Windows::Forms::Label^  label15;
    private: System::Windows::Forms::ComboBox^  cboLeft;
    private: System::Windows::Forms::Label^  label14;
    private: System::Windows::Forms::ComboBox^  cboUpDownPair;
    private: System::Windows::Forms::Label^  label13;
    private: System::Windows::Forms::ComboBox^  cboLeftRightPair;
    private: System::Windows::Forms::Label^  label7;
    private: System::Windows::Forms::Label^  lblLeftRightTriggerDistanceValue;
    private: System::Windows::Forms::TrackBar^  trackLeftRightTriggerDistance;
    private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  lblUpDownTriggerDistanceValue;
private: System::Windows::Forms::TrackBar^  trackUpDownTriggerDistance;
private: System::Windows::Forms::CheckBox^  chkReverseScroll;
private: System::Windows::Forms::CheckBox^  chkDisableScrolling;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::RichTextBox^  richTextBox1;
private: System::Windows::Forms::LinkLabel^  linkLabel1;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label21;


    private: System::Windows::Forms::ToolStripSeparator^  sepOne;

    private:
        void UpdateControls()
        {
            // action
            trackLeftRightTriggerDistance->Value = fConfigurations->getActionConfiguration()->getLeftRightTriggerDistancePercent();
            trackUpDownTriggerDistance->Value = fConfigurations->getActionConfiguration()->getUpDownTriggerDistancePercent();

            cboLeftRightPair->SelectedIndex = fConfigurations->getActionConfiguration()->getLeftRightPairedAction().getPersistentValue();
            cboUpDownPair->SelectedIndex = fConfigurations->getActionConfiguration()->getUpDownPairedAction().getPersistentValue();

            cboLeft->SelectedIndex = fConfigurations->getActionConfiguration()->getLeftAction().getPersistentValue();
            cboRight->SelectedIndex = fConfigurations->getActionConfiguration()->getRightAction().getPersistentValue();
            cboUp->SelectedIndex = fConfigurations->getActionConfiguration()->getUpAction().getPersistentValue();
            cboDown->SelectedIndex = fConfigurations->getActionConfiguration()->getDownAction().getPersistentValue();

            // general
            chkStartWithWindows->Checked = fConfigurations->getGeneralConfiguration()->isStartWithWindowsEnabled();

            // scrolling
            trackSpeed->Value = fConfigurations->getScrollConfiguration()->getSpeed();
            chkAcceleration->Checked = fConfigurations->getScrollConfiguration()->isAccelerationEnabled();
            trackAcceleration->Value = trackAcceleration->Maximum + trackAcceleration->Minimum - fConfigurations->getScrollConfiguration()->getAccelerationFactor();
            trackDeltaRatioThreshold->Value = fConfigurations->getScrollConfiguration()->getDeltaRatioThreshold();
            trackScrollMaxZThreshold->Value = fConfigurations->getScrollConfiguration()->getMaxZThreshold();
            cboEasingAlgorithm->SelectedIndex = EasingAlgorithm::mapPersistentValue(fConfigurations->getScrollConfiguration()->getInertialScrollEasingAlgorithm());
            trackInertialScrollDuration->Value = fConfigurations->getScrollConfiguration()->getInertialScrollDuration();
			chkReverseScroll->Checked = fConfigurations->getScrollConfiguration()->isReverseScrollingEnabled();

            // tapping
            trackSingleTapIntervalThreshold->Value = fConfigurations->getTapConfiguration()->getSingleTapIntervalThreshold();
            trackTapMaxDistance->Value = fConfigurations->getTapConfiguration()->getMaxDistance();
            cboOneFinger->SelectedIndex = fConfigurations->getTapConfiguration()->getMouseButton(1).getPersistentValue();
            cboTwoFinger->SelectedIndex = fConfigurations->getTapConfiguration()->getMouseButton(2).getPersistentValue();
            cboThreeFinger->SelectedIndex = fConfigurations->getTapConfiguration()->getMouseButton(3).getPersistentValue();
            trackTapMaxWThreshold->Value = fConfigurations->getTapConfiguration()->getMaxWThreshold();
            trackTapMaxZThreshold->Value = fConfigurations->getTapConfiguration()->getMaxZThreshold();

            lblSingleTapIntervalThresholdValue->Text = trackSingleTapIntervalThreshold->Value.ToString();
            lblSpeedValue->Text = trackSpeed->Value.ToString();
            lblAccelerationValue->Text = trackAcceleration->Value.ToString();
            lblTapMaxDistanceValue->Text = trackTapMaxDistance->Value.ToString();
            lblInertialScrollDurationValue->Text = trackInertialScrollDuration->Value.ToString();
            lblTapMaxWThresholdValue->Text = trackTapMaxWThreshold->Value.ToString();
            lblTapMaxZThresholdValue->Text = trackTapMaxZThreshold->Value.ToString();
            lblScrollMaxZThresholdValue->Text = trackScrollMaxZThreshold->Value.ToString();
            lblDeltaRatioThresholdValue->Text = trackDeltaRatioThreshold->Value.ToString();
            lblLeftRightTriggerDistanceValue->Text = trackLeftRightTriggerDistance->Value.ToString() + "%";
            lblUpDownTriggerDistanceValue->Text = trackUpDownTriggerDistance->Value.ToString() + "%";

            disableButtons();
        }

        void UpdateConfigurations()
        {
            fConfigurations->getActionConfiguration()->update
            (
                trackLeftRightTriggerDistance->Value,
                trackUpDownTriggerDistance->Value,
                cboLeftRightPair->SelectedIndex,
                cboUpDownPair->SelectedIndex,
                cboLeft->SelectedIndex,
                cboRight->SelectedIndex,
                cboUp->SelectedIndex,
                cboDown->SelectedIndex
            );
            fConfigurations->getGeneralConfiguration()->update(chkStartWithWindows->Checked);
            fConfigurations->getScrollConfiguration()->update
            (
                trackAcceleration->Maximum + trackAcceleration->Minimum - trackAcceleration->Value,
                chkAcceleration->Checked,
                trackDeltaRatioThreshold->Value,
                trackInertialScrollDuration->Value,
                EasingAlgorithm::map(cboEasingAlgorithm->SelectedIndex),
                trackScrollMaxZThreshold->Value,
                trackSpeed->Value,
				chkReverseScroll->Checked
            );
            fConfigurations->getTapConfiguration()->update
            (
                trackSingleTapIntervalThreshold->Value,
                trackTapMaxDistance->Value,
                trackTapMaxWThreshold->Value,
                trackTapMaxZThreshold->Value,
                cboOneFinger->SelectedIndex,
                cboTwoFinger->SelectedIndex,
                cboThreeFinger->SelectedIndex
            );
            fConfigurations->save();
            disableButtons();
        }

        void disableButtons()
        {
            btnApply->Enabled = false;
        }

        void enableButtons()
        {
            btnApply->Enabled = true;
        }

		void disableScrolling()
		{
			trackSpeed->Value = 0;
			trackSpeed->Enabled = false;
		}
		void enableScrolling()
		{
			trackSpeed->Value = fConfigurations->getScrollConfiguration()->getSpeed();
			trackSpeed->Enabled = false;
		}

        ApplicationContext^ fParentAppContext;
        Configurations^ fConfigurations;
        frmPacketObserver^ fPacketObserverForm;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

    private: System::Windows::Forms::Button^  btnSave;
    private: System::Windows::Forms::Button^  btnCancel;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmSettings::typeid));
			this->notifyIcon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->ctxtNotifyIcon = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->mniSettings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepOne = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mniExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->tabSettings = (gcnew System::Windows::Forms::TabControl());
			this->tbpGeneral = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->chkStartWithWindows = (gcnew System::Windows::Forms::CheckBox());
			this->tbpScrolling = (gcnew System::Windows::Forms::TabPage());
			this->chkDisableScrolling = (gcnew System::Windows::Forms::CheckBox());
			this->chkReverseScroll = (gcnew System::Windows::Forms::CheckBox());
			this->lblDeltaRatioThresholdValue = (gcnew System::Windows::Forms::Label());
			this->trackDeltaRatioThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lblScrollMaxZThresholdValue = (gcnew System::Windows::Forms::Label());
			this->trackScrollMaxZThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblInertialScrollDurationValue = (gcnew System::Windows::Forms::Label());
			this->trackInertialScrollDuration = (gcnew System::Windows::Forms::TrackBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cboEasingAlgorithm = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->chkAcceleration = (gcnew System::Windows::Forms::CheckBox());
			this->lblAccelerationValue = (gcnew System::Windows::Forms::Label());
			this->trackAcceleration = (gcnew System::Windows::Forms::TrackBar());
			this->lblSpeedValue = (gcnew System::Windows::Forms::Label());
			this->trackSpeed = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbpTapping = (gcnew System::Windows::Forms::TabPage());
			this->lblTapMaxZThresholdValue = (gcnew System::Windows::Forms::Label());
			this->trackTapMaxZThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lblTapMaxWThresholdValue = (gcnew System::Windows::Forms::Label());
			this->trackTapMaxWThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lblTapMaxDistanceValue = (gcnew System::Windows::Forms::Label());
			this->trackTapMaxDistance = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cboThreeFinger = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cboTwoFinger = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cboOneFinger = (gcnew System::Windows::Forms::ComboBox());
			this->lblOneFinger = (gcnew System::Windows::Forms::Label());
			this->lblSingleTapIntervalThresholdValue = (gcnew System::Windows::Forms::Label());
			this->trackSingleTapIntervalThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabActions = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->lblUpDownTriggerDistanceValue = (gcnew System::Windows::Forms::Label());
			this->trackUpDownTriggerDistance = (gcnew System::Windows::Forms::TrackBar());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->lblLeftRightTriggerDistanceValue = (gcnew System::Windows::Forms::Label());
			this->trackLeftRightTriggerDistance = (gcnew System::Windows::Forms::TrackBar());
			this->cboDown = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->cboUp = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->cboRight = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->cboLeft = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->cboUpDownPair = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->cboLeftRightPair = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnApply = (gcnew System::Windows::Forms::Button());
			this->btnPacketObserver = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->ctxtNotifyIcon->SuspendLayout();
			this->tabSettings->SuspendLayout();
			this->tbpGeneral->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tbpScrolling->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackDeltaRatioThreshold))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackScrollMaxZThreshold))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackInertialScrollDuration))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackAcceleration))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackSpeed))->BeginInit();
			this->tbpTapping->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackTapMaxZThreshold))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackTapMaxWThreshold))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackTapMaxDistance))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackSingleTapIntervalThreshold))->BeginInit();
			this->tabActions->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackUpDownTriggerDistance))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackLeftRightTriggerDistance))->BeginInit();
			this->SuspendLayout();
			// 
			// notifyIcon
			// 
			this->notifyIcon->ContextMenuStrip = this->ctxtNotifyIcon;
			this->notifyIcon->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon.Icon")));
			this->notifyIcon->Text = L"envy TouchPad";
			this->notifyIcon->Visible = true;
			this->notifyIcon->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmSettings::notifyIconApp_MouseDoubleClick);
			// 
			// ctxtNotifyIcon
			// 
			this->ctxtNotifyIcon->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mniSettings, 
				this->sepOne, this->mniExit});
			this->ctxtNotifyIcon->Name = L"ctxtNotifyIcon";
			this->ctxtNotifyIcon->Size = System::Drawing::Size(148, 54);
			// 
			// mniSettings
			// 
			this->mniSettings->Name = L"mniSettings";
			this->mniSettings->Size = System::Drawing::Size(147, 22);
			this->mniSettings->Text = L"&Open settings";
			this->mniSettings->Click += gcnew System::EventHandler(this, &frmSettings::mniSettings_Click);
			// 
			// sepOne
			// 
			this->sepOne->Name = L"sepOne";
			this->sepOne->Size = System::Drawing::Size(144, 6);
			// 
			// mniExit
			// 
			this->mniExit->Name = L"mniExit";
			this->mniExit->Size = System::Drawing::Size(147, 22);
			this->mniExit->Text = L"E&xit";
			this->mniExit->Click += gcnew System::EventHandler(this, &frmSettings::mniExit_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(69, 484);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(85, 30);
			this->btnSave->TabIndex = 1;
			this->btnSave->Text = L"&Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmSettings::btnSave_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(160, 484);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(85, 30);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"&Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmSettings::btnCancel_Click);
			// 
			// tabSettings
			// 
			this->tabSettings->Controls->Add(this->tbpGeneral);
			this->tabSettings->Controls->Add(this->tbpScrolling);
			this->tabSettings->Controls->Add(this->tbpTapping);
			this->tabSettings->Controls->Add(this->tabActions);
			this->tabSettings->Location = System::Drawing::Point(12, 12);
			this->tabSettings->Name = L"tabSettings";
			this->tabSettings->SelectedIndex = 0;
			this->tabSettings->Size = System::Drawing::Size(377, 466);
			this->tabSettings->TabIndex = 3;
			// 
			// tbpGeneral
			// 
			this->tbpGeneral->Controls->Add(this->groupBox4);
			this->tbpGeneral->Controls->Add(this->chkStartWithWindows);
			this->tbpGeneral->Location = System::Drawing::Point(4, 22);
			this->tbpGeneral->Name = L"tbpGeneral";
			this->tbpGeneral->Padding = System::Windows::Forms::Padding(3);
			this->tbpGeneral->Size = System::Drawing::Size(369, 440);
			this->tbpGeneral->TabIndex = 0;
			this->tbpGeneral->Text = L"General";
			this->tbpGeneral->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label21);
			this->groupBox4->Controls->Add(this->richTextBox1);
			this->groupBox4->Controls->Add(this->linkLabel1);
			this->groupBox4->Controls->Add(this->label20);
			this->groupBox4->Controls->Add(this->textBox2);
			this->groupBox4->Controls->Add(this->textBox1);
			this->groupBox4->Location = System::Drawing::Point(15, 87);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(339, 347);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"About";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(6, 116);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(327, 98);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = resources->GetString(L"textBox2.Text");
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 19);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(327, 91);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Envy TouchPad is an open source project.\r\nI found the source on the web time ago," 
				L" I don\'t know where or from who.\r\nPlease if you are the original author or if yo" 
				L"u know some reference tell me.\r\n";
			// 
			// chkStartWithWindows
			// 
			this->chkStartWithWindows->AutoSize = true;
			this->chkStartWithWindows->Location = System::Drawing::Point(6, 12);
			this->chkStartWithWindows->Name = L"chkStartWithWindows";
			this->chkStartWithWindows->Size = System::Drawing::Size(117, 17);
			this->chkStartWithWindows->TabIndex = 0;
			this->chkStartWithWindows->Text = L"Start with Windows";
			this->chkStartWithWindows->UseVisualStyleBackColor = true;
			this->chkStartWithWindows->CheckedChanged += gcnew System::EventHandler(this, &frmSettings::chkStartWithWindows_CheckedChanged);
			// 
			// tbpScrolling
			// 
			this->tbpScrolling->Controls->Add(this->chkDisableScrolling);
			this->tbpScrolling->Controls->Add(this->chkReverseScroll);
			this->tbpScrolling->Controls->Add(this->lblDeltaRatioThresholdValue);
			this->tbpScrolling->Controls->Add(this->trackDeltaRatioThreshold);
			this->tbpScrolling->Controls->Add(this->label12);
			this->tbpScrolling->Controls->Add(this->lblScrollMaxZThresholdValue);
			this->tbpScrolling->Controls->Add(this->trackScrollMaxZThreshold);
			this->tbpScrolling->Controls->Add(this->label11);
			this->tbpScrolling->Controls->Add(this->groupBox1);
			this->tbpScrolling->Controls->Add(this->chkAcceleration);
			this->tbpScrolling->Controls->Add(this->lblAccelerationValue);
			this->tbpScrolling->Controls->Add(this->trackAcceleration);
			this->tbpScrolling->Controls->Add(this->lblSpeedValue);
			this->tbpScrolling->Controls->Add(this->trackSpeed);
			this->tbpScrolling->Controls->Add(this->label5);
			this->tbpScrolling->Location = System::Drawing::Point(4, 22);
			this->tbpScrolling->Name = L"tbpScrolling";
			this->tbpScrolling->Padding = System::Windows::Forms::Padding(3);
			this->tbpScrolling->Size = System::Drawing::Size(369, 440);
			this->tbpScrolling->TabIndex = 1;
			this->tbpScrolling->Text = L"Scrolling";
			this->tbpScrolling->UseVisualStyleBackColor = true;
			// 
			// chkDisableScrolling
			// 
			this->chkDisableScrolling->AutoSize = true;
			this->chkDisableScrolling->Location = System::Drawing::Point(3, 12);
			this->chkDisableScrolling->Name = L"chkDisableScrolling";
			this->chkDisableScrolling->Size = System::Drawing::Size(219, 17);
			this->chkDisableScrolling->TabIndex = 25;
			this->chkDisableScrolling->Text = L"Disable Two Finger Scrolling Managment";
			this->chkDisableScrolling->UseVisualStyleBackColor = true;
			this->chkDisableScrolling->CheckedChanged += gcnew System::EventHandler(this, &frmSettings::checkBox1_CheckedChanged);
			// 
			// chkReverseScroll
			// 
			this->chkReverseScroll->AutoSize = true;
			this->chkReverseScroll->Location = System::Drawing::Point(3, 40);
			this->chkReverseScroll->Name = L"chkReverseScroll";
			this->chkReverseScroll->Size = System::Drawing::Size(109, 17);
			this->chkReverseScroll->TabIndex = 24;
			this->chkReverseScroll->Text = L"Reverse Scrolling";
			this->chkReverseScroll->UseVisualStyleBackColor = true;
			this->chkReverseScroll->CheckedChanged += gcnew System::EventHandler(this, &frmSettings::chkReverseScroll_CheckedChanged);
			// 
			// lblDeltaRatioThresholdValue
			// 
			this->lblDeltaRatioThresholdValue->AutoSize = true;
			this->lblDeltaRatioThresholdValue->Location = System::Drawing::Point(341, 269);
			this->lblDeltaRatioThresholdValue->Name = L"lblDeltaRatioThresholdValue";
			this->lblDeltaRatioThresholdValue->Size = System::Drawing::Size(25, 13);
			this->lblDeltaRatioThresholdValue->TabIndex = 23;
			this->lblDeltaRatioThresholdValue->Text = L"000";
			this->lblDeltaRatioThresholdValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackDeltaRatioThreshold
			// 
			this->trackDeltaRatioThreshold->BackColor = System::Drawing::SystemColors::Window;
			this->trackDeltaRatioThreshold->Location = System::Drawing::Point(6, 269);
			this->trackDeltaRatioThreshold->Maximum = 100;
			this->trackDeltaRatioThreshold->Name = L"trackDeltaRatioThreshold";
			this->trackDeltaRatioThreshold->Size = System::Drawing::Size(326, 45);
			this->trackDeltaRatioThreshold->TabIndex = 22;
			this->trackDeltaRatioThreshold->TickFrequency = 5;
			this->trackDeltaRatioThreshold->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackDeltaRatioThreshold->Value = 50;
			this->trackDeltaRatioThreshold->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackDeltaRatioThreshold_ValueChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(0, 253);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(104, 13);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Delta ratio threshold:";
			// 
			// lblScrollMaxZThresholdValue
			// 
			this->lblScrollMaxZThresholdValue->AutoSize = true;
			this->lblScrollMaxZThresholdValue->Location = System::Drawing::Point(338, 205);
			this->lblScrollMaxZThresholdValue->Name = L"lblScrollMaxZThresholdValue";
			this->lblScrollMaxZThresholdValue->Size = System::Drawing::Size(25, 13);
			this->lblScrollMaxZThresholdValue->TabIndex = 20;
			this->lblScrollMaxZThresholdValue->Text = L"000";
			this->lblScrollMaxZThresholdValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackScrollMaxZThreshold
			// 
			this->trackScrollMaxZThreshold->BackColor = System::Drawing::SystemColors::Window;
			this->trackScrollMaxZThreshold->LargeChange = 10;
			this->trackScrollMaxZThreshold->Location = System::Drawing::Point(3, 205);
			this->trackScrollMaxZThreshold->Maximum = 255;
			this->trackScrollMaxZThreshold->Minimum = 50;
			this->trackScrollMaxZThreshold->Name = L"trackScrollMaxZThreshold";
			this->trackScrollMaxZThreshold->Size = System::Drawing::Size(329, 45);
			this->trackScrollMaxZThreshold->SmallChange = 5;
			this->trackScrollMaxZThreshold->TabIndex = 19;
			this->trackScrollMaxZThreshold->TickFrequency = 10;
			this->trackScrollMaxZThreshold->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackScrollMaxZThreshold->Value = 50;
			this->trackScrollMaxZThreshold->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackScrollMaxZThreshold_ValueChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(0, 186);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(108, 13);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Maximum z threshold:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblInertialScrollDurationValue);
			this->groupBox1->Controls->Add(this->trackInertialScrollDuration);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->cboEasingAlgorithm);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(7, 320);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(356, 116);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Inertial";
			// 
			// lblInertialScrollDurationValue
			// 
			this->lblInertialScrollDurationValue->AutoSize = true;
			this->lblInertialScrollDurationValue->Location = System::Drawing::Point(325, 53);
			this->lblInertialScrollDurationValue->Name = L"lblInertialScrollDurationValue";
			this->lblInertialScrollDurationValue->Size = System::Drawing::Size(25, 13);
			this->lblInertialScrollDurationValue->TabIndex = 8;
			this->lblInertialScrollDurationValue->Text = L"000";
			this->lblInertialScrollDurationValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackInertialScrollDuration
			// 
			this->trackInertialScrollDuration->BackColor = System::Drawing::SystemColors::Window;
			this->trackInertialScrollDuration->LargeChange = 100;
			this->trackInertialScrollDuration->Location = System::Drawing::Point(3, 69);
			this->trackInertialScrollDuration->Maximum = 2000;
			this->trackInertialScrollDuration->Minimum = 100;
			this->trackInertialScrollDuration->Name = L"trackInertialScrollDuration";
			this->trackInertialScrollDuration->Size = System::Drawing::Size(322, 45);
			this->trackInertialScrollDuration->SmallChange = 10;
			this->trackInertialScrollDuration->TabIndex = 7;
			this->trackInertialScrollDuration->TickFrequency = 100;
			this->trackInertialScrollDuration->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackInertialScrollDuration->Value = 100;
			this->trackInertialScrollDuration->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackInertialScrollDuration_ValueChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 53);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(50, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Duration:";
			// 
			// cboEasingAlgorithm
			// 
			this->cboEasingAlgorithm->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboEasingAlgorithm->FormattingEnabled = true;
			this->cboEasingAlgorithm->Items->AddRange(gcnew cli::array< System::Object^  >(26) {L"No inertia", L"easeInCirc", L"easeOutCirc", 
				L"easeInOutCirc", L"easeInCubic", L"easeOutCubic", L"easeInOutCubic", L"easeInExpo", L"easeOutExpo", L"easeInOutExpo", L"easeNoneLinear", 
				L"easeInLinear", L"easeOutLinear", L"easeInOutLinear", L"easeInQuad", L"easeOutQuad", L"easeInOutQuad", L"easeInQuart", L"easeOutQuart", 
				L"easeInOutQuart", L"easeInQuint", L"easeOutQuint", L"easeInOutQuint", L"easeInSine", L"easeOutSine", L"easeInOutSine"});
			this->cboEasingAlgorithm->Location = System::Drawing::Point(169, 19);
			this->cboEasingAlgorithm->Name = L"cboEasingAlgorithm";
			this->cboEasingAlgorithm->Size = System::Drawing::Size(128, 21);
			this->cboEasingAlgorithm->TabIndex = 1;
			this->cboEasingAlgorithm->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboEasingAlgorithm_SelectedValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Easing algorithm:";
			// 
			// chkAcceleration
			// 
			this->chkAcceleration->AutoSize = true;
			this->chkAcceleration->Location = System::Drawing::Point(3, 127);
			this->chkAcceleration->Name = L"chkAcceleration";
			this->chkAcceleration->Size = System::Drawing::Size(85, 17);
			this->chkAcceleration->TabIndex = 8;
			this->chkAcceleration->Text = L"Acceleration";
			this->chkAcceleration->UseVisualStyleBackColor = true;
			// 
			// lblAccelerationValue
			// 
			this->lblAccelerationValue->AutoSize = true;
			this->lblAccelerationValue->Location = System::Drawing::Point(338, 146);
			this->lblAccelerationValue->Name = L"lblAccelerationValue";
			this->lblAccelerationValue->Size = System::Drawing::Size(25, 13);
			this->lblAccelerationValue->TabIndex = 7;
			this->lblAccelerationValue->Text = L"000";
			this->lblAccelerationValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackAcceleration
			// 
			this->trackAcceleration->BackColor = System::Drawing::SystemColors::Window;
			this->trackAcceleration->LargeChange = 10;
			this->trackAcceleration->Location = System::Drawing::Point(3, 146);
			this->trackAcceleration->Maximum = 150;
			this->trackAcceleration->Minimum = 20;
			this->trackAcceleration->Name = L"trackAcceleration";
			this->trackAcceleration->Size = System::Drawing::Size(329, 45);
			this->trackAcceleration->SmallChange = 5;
			this->trackAcceleration->TabIndex = 6;
			this->trackAcceleration->TickFrequency = 10;
			this->trackAcceleration->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackAcceleration->Value = 20;
			this->trackAcceleration->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackAcceleration_ValueChanged);
			// 
			// lblSpeedValue
			// 
			this->lblSpeedValue->AutoSize = true;
			this->lblSpeedValue->Location = System::Drawing::Point(341, 82);
			this->lblSpeedValue->Name = L"lblSpeedValue";
			this->lblSpeedValue->Size = System::Drawing::Size(25, 13);
			this->lblSpeedValue->TabIndex = 5;
			this->lblSpeedValue->Text = L"000";
			this->lblSpeedValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackSpeed
			// 
			this->trackSpeed->BackColor = System::Drawing::SystemColors::Window;
			this->trackSpeed->LargeChange = 10;
			this->trackSpeed->Location = System::Drawing::Point(6, 82);
			this->trackSpeed->Maximum = 250;
			this->trackSpeed->Name = L"trackSpeed";
			this->trackSpeed->Size = System::Drawing::Size(326, 45);
			this->trackSpeed->SmallChange = 5;
			this->trackSpeed->TabIndex = 4;
			this->trackSpeed->TickFrequency = 10;
			this->trackSpeed->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackSpeed->Value = 100;
			this->trackSpeed->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackSpeed_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(-3, 66);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Speed:";
			// 
			// tbpTapping
			// 
			this->tbpTapping->Controls->Add(this->lblTapMaxZThresholdValue);
			this->tbpTapping->Controls->Add(this->trackTapMaxZThreshold);
			this->tbpTapping->Controls->Add(this->label10);
			this->tbpTapping->Controls->Add(this->lblTapMaxWThresholdValue);
			this->tbpTapping->Controls->Add(this->trackTapMaxWThreshold);
			this->tbpTapping->Controls->Add(this->label9);
			this->tbpTapping->Controls->Add(this->lblTapMaxDistanceValue);
			this->tbpTapping->Controls->Add(this->trackTapMaxDistance);
			this->tbpTapping->Controls->Add(this->label6);
			this->tbpTapping->Controls->Add(this->cboThreeFinger);
			this->tbpTapping->Controls->Add(this->label3);
			this->tbpTapping->Controls->Add(this->cboTwoFinger);
			this->tbpTapping->Controls->Add(this->label2);
			this->tbpTapping->Controls->Add(this->cboOneFinger);
			this->tbpTapping->Controls->Add(this->lblOneFinger);
			this->tbpTapping->Controls->Add(this->lblSingleTapIntervalThresholdValue);
			this->tbpTapping->Controls->Add(this->trackSingleTapIntervalThreshold);
			this->tbpTapping->Controls->Add(this->label1);
			this->tbpTapping->Location = System::Drawing::Point(4, 22);
			this->tbpTapping->Name = L"tbpTapping";
			this->tbpTapping->Size = System::Drawing::Size(369, 440);
			this->tbpTapping->TabIndex = 2;
			this->tbpTapping->Text = L"Tapping";
			this->tbpTapping->UseVisualStyleBackColor = true;
			// 
			// lblTapMaxZThresholdValue
			// 
			this->lblTapMaxZThresholdValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblTapMaxZThresholdValue->AutoSize = true;
			this->lblTapMaxZThresholdValue->Location = System::Drawing::Point(341, 290);
			this->lblTapMaxZThresholdValue->Name = L"lblTapMaxZThresholdValue";
			this->lblTapMaxZThresholdValue->Size = System::Drawing::Size(25, 13);
			this->lblTapMaxZThresholdValue->TabIndex = 17;
			this->lblTapMaxZThresholdValue->Text = L"000";
			this->lblTapMaxZThresholdValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackTapMaxZThreshold
			// 
			this->trackTapMaxZThreshold->BackColor = System::Drawing::SystemColors::Window;
			this->trackTapMaxZThreshold->LargeChange = 10;
			this->trackTapMaxZThreshold->Location = System::Drawing::Point(6, 290);
			this->trackTapMaxZThreshold->Maximum = 255;
			this->trackTapMaxZThreshold->Minimum = 50;
			this->trackTapMaxZThreshold->Name = L"trackTapMaxZThreshold";
			this->trackTapMaxZThreshold->Size = System::Drawing::Size(314, 45);
			this->trackTapMaxZThreshold->SmallChange = 5;
			this->trackTapMaxZThreshold->TabIndex = 16;
			this->trackTapMaxZThreshold->TickFrequency = 10;
			this->trackTapMaxZThreshold->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackTapMaxZThreshold->Value = 50;
			this->trackTapMaxZThreshold->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackTapMaxZThreshold_ValueChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 271);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(108, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Maximum z threshold:";
			// 
			// lblTapMaxWThresholdValue
			// 
			this->lblTapMaxWThresholdValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblTapMaxWThresholdValue->AutoSize = true;
			this->lblTapMaxWThresholdValue->Location = System::Drawing::Point(341, 231);
			this->lblTapMaxWThresholdValue->Name = L"lblTapMaxWThresholdValue";
			this->lblTapMaxWThresholdValue->Size = System::Drawing::Size(25, 13);
			this->lblTapMaxWThresholdValue->TabIndex = 14;
			this->lblTapMaxWThresholdValue->Text = L"000";
			this->lblTapMaxWThresholdValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackTapMaxWThreshold
			// 
			this->trackTapMaxWThreshold->BackColor = System::Drawing::SystemColors::Window;
			this->trackTapMaxWThreshold->Location = System::Drawing::Point(6, 231);
			this->trackTapMaxWThreshold->Maximum = 50;
			this->trackTapMaxWThreshold->Minimum = 5;
			this->trackTapMaxWThreshold->Name = L"trackTapMaxWThreshold";
			this->trackTapMaxWThreshold->Size = System::Drawing::Size(314, 45);
			this->trackTapMaxWThreshold->TabIndex = 13;
			this->trackTapMaxWThreshold->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackTapMaxWThreshold->Value = 15;
			this->trackTapMaxWThreshold->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackTapMaxWThreshold_ValueChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 212);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(111, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Maximum w threshold:";
			// 
			// lblTapMaxDistanceValue
			// 
			this->lblTapMaxDistanceValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblTapMaxDistanceValue->AutoSize = true;
			this->lblTapMaxDistanceValue->Location = System::Drawing::Point(341, 172);
			this->lblTapMaxDistanceValue->Name = L"lblTapMaxDistanceValue";
			this->lblTapMaxDistanceValue->Size = System::Drawing::Size(25, 13);
			this->lblTapMaxDistanceValue->TabIndex = 11;
			this->lblTapMaxDistanceValue->Text = L"000";
			this->lblTapMaxDistanceValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackTapMaxDistance
			// 
			this->trackTapMaxDistance->BackColor = System::Drawing::SystemColors::Window;
			this->trackTapMaxDistance->Location = System::Drawing::Point(6, 172);
			this->trackTapMaxDistance->Maximum = 100;
			this->trackTapMaxDistance->Minimum = 5;
			this->trackTapMaxDistance->Name = L"trackTapMaxDistance";
			this->trackTapMaxDistance->Size = System::Drawing::Size(314, 45);
			this->trackTapMaxDistance->TabIndex = 10;
			this->trackTapMaxDistance->TickFrequency = 5;
			this->trackTapMaxDistance->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackTapMaxDistance->Value = 25;
			this->trackTapMaxDistance->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackTapMaxDistance_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 153);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(155, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Maximum finger travel distance:";
			// 
			// cboThreeFinger
			// 
			this->cboThreeFinger->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboThreeFinger->FormattingEnabled = true;
			this->cboThreeFinger->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Disabled", L"Left", L"Middle", L"Right", 
				L"X One", L"X Two"});
			this->cboThreeFinger->Location = System::Drawing::Point(54, 67);
			this->cboThreeFinger->Name = L"cboThreeFinger";
			this->cboThreeFinger->Size = System::Drawing::Size(266, 21);
			this->cboThreeFinger->TabIndex = 8;
			this->cboThreeFinger->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboThreeFinger_SelectedValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"3 finger:";
			// 
			// cboTwoFinger
			// 
			this->cboTwoFinger->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTwoFinger->FormattingEnabled = true;
			this->cboTwoFinger->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Disabled", L"Left", L"Middle", L"Right", L"X One", 
				L"X Two"});
			this->cboTwoFinger->Location = System::Drawing::Point(54, 40);
			this->cboTwoFinger->Name = L"cboTwoFinger";
			this->cboTwoFinger->Size = System::Drawing::Size(266, 21);
			this->cboTwoFinger->TabIndex = 6;
			this->cboTwoFinger->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboTwoFinger_SelectedValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"2 finger:";
			// 
			// cboOneFinger
			// 
			this->cboOneFinger->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboOneFinger->FormattingEnabled = true;
			this->cboOneFinger->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Disabled", L"Left", L"Middle", L"Right", L"X One", 
				L"X Two"});
			this->cboOneFinger->Location = System::Drawing::Point(54, 13);
			this->cboOneFinger->Name = L"cboOneFinger";
			this->cboOneFinger->Size = System::Drawing::Size(266, 21);
			this->cboOneFinger->TabIndex = 4;
			this->cboOneFinger->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboOneFinger_SelectedValueChanged);
			// 
			// lblOneFinger
			// 
			this->lblOneFinger->AutoSize = true;
			this->lblOneFinger->Location = System::Drawing::Point(3, 16);
			this->lblOneFinger->Name = L"lblOneFinger";
			this->lblOneFinger->Size = System::Drawing::Size(45, 13);
			this->lblOneFinger->TabIndex = 3;
			this->lblOneFinger->Text = L"1 finger:";
			// 
			// lblSingleTapIntervalThresholdValue
			// 
			this->lblSingleTapIntervalThresholdValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblSingleTapIntervalThresholdValue->AutoSize = true;
			this->lblSingleTapIntervalThresholdValue->Location = System::Drawing::Point(341, 114);
			this->lblSingleTapIntervalThresholdValue->Name = L"lblSingleTapIntervalThresholdValue";
			this->lblSingleTapIntervalThresholdValue->Size = System::Drawing::Size(25, 13);
			this->lblSingleTapIntervalThresholdValue->TabIndex = 2;
			this->lblSingleTapIntervalThresholdValue->Text = L"000";
			this->lblSingleTapIntervalThresholdValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackSingleTapIntervalThreshold
			// 
			this->trackSingleTapIntervalThreshold->BackColor = System::Drawing::SystemColors::Window;
			this->trackSingleTapIntervalThreshold->LargeChange = 25;
			this->trackSingleTapIntervalThreshold->Location = System::Drawing::Point(6, 114);
			this->trackSingleTapIntervalThreshold->Maximum = 500;
			this->trackSingleTapIntervalThreshold->Minimum = 25;
			this->trackSingleTapIntervalThreshold->Name = L"trackSingleTapIntervalThreshold";
			this->trackSingleTapIntervalThreshold->Size = System::Drawing::Size(314, 45);
			this->trackSingleTapIntervalThreshold->SmallChange = 5;
			this->trackSingleTapIntervalThreshold->TabIndex = 1;
			this->trackSingleTapIntervalThreshold->TickFrequency = 25;
			this->trackSingleTapIntervalThreshold->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackSingleTapIntervalThreshold->Value = 25;
			this->trackSingleTapIntervalThreshold->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackSingleTapIntervalThreshold_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 95);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Single tap interval threshold:";
			// 
			// tabActions
			// 
			this->tabActions->Controls->Add(this->groupBox2);
			this->tabActions->Location = System::Drawing::Point(4, 22);
			this->tabActions->Name = L"tabActions";
			this->tabActions->Padding = System::Windows::Forms::Padding(3);
			this->tabActions->Size = System::Drawing::Size(369, 440);
			this->tabActions->TabIndex = 3;
			this->tabActions->Text = L"Actions";
			this->tabActions->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->groupBox3);
			this->groupBox2->Controls->Add(this->cboDown);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->cboUp);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->cboRight);
			this->groupBox2->Controls->Add(this->label15);
			this->groupBox2->Controls->Add(this->cboLeft);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->cboUpDownPair);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->cboLeftRightPair);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Location = System::Drawing::Point(6, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(357, 422);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Three Finger Scroll";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Controls->Add(this->lblUpDownTriggerDistanceValue);
			this->groupBox3->Controls->Add(this->trackUpDownTriggerDistance);
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->lblLeftRightTriggerDistanceValue);
			this->groupBox3->Controls->Add(this->trackLeftRightTriggerDistance);
			this->groupBox3->Location = System::Drawing::Point(2, 266);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(349, 150);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Trigger Distance";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(3, 86);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(57, 13);
			this->label18->TabIndex = 19;
			this->label18->Text = L"Up/Down:";
			// 
			// lblUpDownTriggerDistanceValue
			// 
			this->lblUpDownTriggerDistanceValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblUpDownTriggerDistanceValue->AutoSize = true;
			this->lblUpDownTriggerDistanceValue->Location = System::Drawing::Point(318, 86);
			this->lblUpDownTriggerDistanceValue->Name = L"lblUpDownTriggerDistanceValue";
			this->lblUpDownTriggerDistanceValue->Size = System::Drawing::Size(25, 13);
			this->lblUpDownTriggerDistanceValue->TabIndex = 21;
			this->lblUpDownTriggerDistanceValue->Text = L"000";
			this->lblUpDownTriggerDistanceValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackUpDownTriggerDistance
			// 
			this->trackUpDownTriggerDistance->BackColor = System::Drawing::SystemColors::Window;
			this->trackUpDownTriggerDistance->Location = System::Drawing::Point(6, 102);
			this->trackUpDownTriggerDistance->Maximum = 50;
			this->trackUpDownTriggerDistance->Minimum = 5;
			this->trackUpDownTriggerDistance->Name = L"trackUpDownTriggerDistance";
			this->trackUpDownTriggerDistance->Size = System::Drawing::Size(306, 45);
			this->trackUpDownTriggerDistance->TabIndex = 20;
			this->trackUpDownTriggerDistance->TickFrequency = 2;
			this->trackUpDownTriggerDistance->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackUpDownTriggerDistance->Value = 25;
			this->trackUpDownTriggerDistance->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackUpDownTriggerDistance_ValueChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(3, 22);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(58, 13);
			this->label19->TabIndex = 16;
			this->label19->Text = L"Left/Right:";
			// 
			// lblLeftRightTriggerDistanceValue
			// 
			this->lblLeftRightTriggerDistanceValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblLeftRightTriggerDistanceValue->AutoSize = true;
			this->lblLeftRightTriggerDistanceValue->Location = System::Drawing::Point(318, 22);
			this->lblLeftRightTriggerDistanceValue->Name = L"lblLeftRightTriggerDistanceValue";
			this->lblLeftRightTriggerDistanceValue->Size = System::Drawing::Size(25, 13);
			this->lblLeftRightTriggerDistanceValue->TabIndex = 18;
			this->lblLeftRightTriggerDistanceValue->Text = L"000";
			this->lblLeftRightTriggerDistanceValue->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// trackLeftRightTriggerDistance
			// 
			this->trackLeftRightTriggerDistance->BackColor = System::Drawing::SystemColors::Window;
			this->trackLeftRightTriggerDistance->Location = System::Drawing::Point(6, 38);
			this->trackLeftRightTriggerDistance->Maximum = 50;
			this->trackLeftRightTriggerDistance->Minimum = 5;
			this->trackLeftRightTriggerDistance->Name = L"trackLeftRightTriggerDistance";
			this->trackLeftRightTriggerDistance->Size = System::Drawing::Size(306, 45);
			this->trackLeftRightTriggerDistance->TabIndex = 17;
			this->trackLeftRightTriggerDistance->TickFrequency = 2;
			this->trackLeftRightTriggerDistance->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackLeftRightTriggerDistance->Value = 25;
			this->trackLeftRightTriggerDistance->ValueChanged += gcnew System::EventHandler(this, &frmSettings::trackLeftRightTriggerDistance_ValueChanged);
			// 
			// cboDown
			// 
			this->cboDown->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDown->FormattingEnabled = true;
			this->cboDown->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"None", L"Mouse Button X 1", L"Mouse Button X 2", 
				L"LWin+~", L"CTRL+WIN+LEFT (left desktop win 10)", L"CTRL+WIN+RIGHT (right desktop win 10)", L"WIN+TAB (multitasking win10)", 
				L"CTRL+D (show desktop)"});
			this->cboDown->Location = System::Drawing::Point(91, 177);
			this->cboDown->Name = L"cboDown";
			this->cboDown->Size = System::Drawing::Size(260, 21);
			this->cboDown->TabIndex = 15;
			this->cboDown->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboDown_SelectedValueChanged);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(7, 180);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(38, 13);
			this->label17->TabIndex = 14;
			this->label17->Text = L"Down:";
			// 
			// cboUp
			// 
			this->cboUp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboUp->FormattingEnabled = true;
			this->cboUp->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"None", L"Mouse Button X 1", L"Mouse Button X 2", 
				L"LWin+~", L"CTRL+WIN+LEFT (left desktop win 10)", L"CTRL+WIN+RIGHT (right desktop win 10)", L"WIN+TAB (multitasking win10)", 
				L"CTRL+D (show desktop)"});
			this->cboUp->Location = System::Drawing::Point(91, 150);
			this->cboUp->Name = L"cboUp";
			this->cboUp->Size = System::Drawing::Size(260, 21);
			this->cboUp->TabIndex = 13;
			this->cboUp->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboUp_SelectedValueChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(7, 153);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(24, 13);
			this->label16->TabIndex = 12;
			this->label16->Text = L"Up:";
			// 
			// cboRight
			// 
			this->cboRight->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRight->FormattingEnabled = true;
			this->cboRight->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"None", L"Mouse Button X 1", L"Mouse Button X 2", 
				L"LWin+~", L"CTRL+WIN+LEFT (left desktop win 10)", L"CTRL+WIN+RIGHT (right desktop win 10)", L"WIN+TAB (multitasking win10)", 
				L"CTRL+D (show desktop)"});
			this->cboRight->Location = System::Drawing::Point(91, 123);
			this->cboRight->Name = L"cboRight";
			this->cboRight->Size = System::Drawing::Size(260, 21);
			this->cboRight->TabIndex = 11;
			this->cboRight->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboRight_SelectedValueChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(7, 126);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(35, 13);
			this->label15->TabIndex = 10;
			this->label15->Text = L"Right:";
			// 
			// cboLeft
			// 
			this->cboLeft->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboLeft->FormattingEnabled = true;
			this->cboLeft->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"None", L"Mouse Button X 1", L"Mouse Button X 2", 
				L"LWin+~", L"CTRL+WIN+LEFT (left desktop win 10)", L"CTRL+WIN+RIGHT (right desktop win 10)", L"WIN+TAB (multitasking win10)", 
				L"CTRL+D (show desktop)"});
			this->cboLeft->Location = System::Drawing::Point(91, 96);
			this->cboLeft->Name = L"cboLeft";
			this->cboLeft->Size = System::Drawing::Size(260, 21);
			this->cboLeft->TabIndex = 9;
			this->cboLeft->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboLeft_SelectedValueChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(7, 99);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(28, 13);
			this->label14->TabIndex = 8;
			this->label14->Text = L"Left:";
			// 
			// cboUpDownPair
			// 
			this->cboUpDownPair->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboUpDownPair->FormattingEnabled = true;
			this->cboUpDownPair->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"Disabled", L"Alt+Shift+Tab / Alt+Tab ", L"Alt+Tab / Alt+Shift+Tab", 
				L"LWin+Tab / LWin+Shift+Tab", L"LWin+Shift+Tab / LWin+Tab", L"Windows10 switch desktop", L"Windows10 switch desktop (reversed)", 
				L"Windows10 show all desktops / show desktop"});
			this->cboUpDownPair->Location = System::Drawing::Point(91, 46);
			this->cboUpDownPair->Name = L"cboUpDownPair";
			this->cboUpDownPair->Size = System::Drawing::Size(260, 21);
			this->cboUpDownPair->TabIndex = 7;
			this->cboUpDownPair->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboUpDownPair_SelectedValueChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(7, 49);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(78, 13);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Up/Down Pair:";
			// 
			// cboLeftRightPair
			// 
			this->cboLeftRightPair->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboLeftRightPair->FormattingEnabled = true;
			this->cboLeftRightPair->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"Disabled", L"Alt+Shift+Tab / Alt+Tab ", 
				L"Alt+Tab / Alt+Shift+Tab", L"LWin+Tab / LWin+Shift+Tab", L"LWin+Shift+Tab / LWin+Tab", L"Windows10 switch desktop", L"Windows10 switch desktop (reversed)", 
				L"Windows10 show all desktops / show desktop"});
			this->cboLeftRightPair->Location = System::Drawing::Point(91, 19);
			this->cboLeftRightPair->Name = L"cboLeftRightPair";
			this->cboLeftRightPair->Size = System::Drawing::Size(260, 21);
			this->cboLeftRightPair->TabIndex = 5;
			this->cboLeftRightPair->SelectedValueChanged += gcnew System::EventHandler(this, &frmSettings::cboLeftRightPair_SelectedValueChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 22);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(79, 13);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Left/Right Pair:";
			// 
			// btnApply
			// 
			this->btnApply->Enabled = false;
			this->btnApply->Location = System::Drawing::Point(251, 484);
			this->btnApply->Name = L"btnApply";
			this->btnApply->Size = System::Drawing::Size(85, 30);
			this->btnApply->TabIndex = 4;
			this->btnApply->Text = L"&Apply";
			this->btnApply->UseVisualStyleBackColor = true;
			this->btnApply->Click += gcnew System::EventHandler(this, &frmSettings::btnApply_Click);
			// 
			// btnPacketObserver
			// 
			this->btnPacketObserver->Location = System::Drawing::Point(12, 484);
			this->btnPacketObserver->Name = L"btnPacketObserver";
			this->btnPacketObserver->Size = System::Drawing::Size(20, 29);
			this->btnPacketObserver->TabIndex = 5;
			this->btnPacketObserver->Text = L"*";
			this->btnPacketObserver->UseVisualStyleBackColor = true;
			this->btnPacketObserver->Click += gcnew System::EventHandler(this, &frmSettings::btnPacketObserver_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(6, 232);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(85, 13);
			this->label20->TabIndex = 3;
			this->label20->Text = L"Original Thread: ";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(6, 265);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(0, 13);
			this->linkLabel1->TabIndex = 4;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(6, 248);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(321, 40);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"http://forum.xda-developers.com/windows-10/development/envy-touchpad-nagashmod-wi" 
				L"ndows-10-best-t3264301#post6416237";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(270, 331);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(63, 13);
			this->label21->TabIndex = 2;
			this->label21->Text = L"Version: 1.0";
			// 
			// frmSettings
			// 
			this->AcceptButton = this->btnSave;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(401, 526);
			this->Controls->Add(this->tabSettings);
			this->Controls->Add(this->btnApply);
			this->Controls->Add(this->btnPacketObserver);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnCancel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"frmSettings";
			this->Text = L"envy TouchPad: NagashMod for Win10 (v1)";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmSettings::frmSettings_FormClosing);
			this->ctxtNotifyIcon->ResumeLayout(false);
			this->tabSettings->ResumeLayout(false);
			this->tbpGeneral->ResumeLayout(false);
			this->tbpGeneral->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tbpScrolling->ResumeLayout(false);
			this->tbpScrolling->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackDeltaRatioThreshold))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackScrollMaxZThreshold))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackInertialScrollDuration))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackAcceleration))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackSpeed))->EndInit();
			this->tbpTapping->ResumeLayout(false);
			this->tbpTapping->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackTapMaxZThreshold))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackTapMaxWThreshold))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackTapMaxDistance))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackSingleTapIntervalThreshold))->EndInit();
			this->tabActions->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackUpDownTriggerDistance))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackLeftRightTriggerDistance))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void notifyIconApp_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
         {
             UpdateControls();
		     this->Show();
             this->Activate();
         }
private: System::Void mniExit_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             notifyIcon->Icon = nullptr;
             notifyIcon->Visible = false;
             fParentAppContext->ExitThread();
         }
private: System::Void mniSettings_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             UpdateControls();
             this->Show();
         }
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             this->Hide();
         }
private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             UpdateConfigurations();
             this->Hide();
         }
private: System::Void trackSingleTapIntervalThreshold_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblSingleTapIntervalThresholdValue->Text = trackSingleTapIntervalThreshold->Value.ToString();
         }
private: System::Void trackSpeed_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblSpeedValue->Text = trackSpeed->Value.ToString();
         }
private: System::Void trackAcceleration_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblAccelerationValue->Text = trackAcceleration->Value.ToString();
         }
private: System::Void trackTapMaxDistance_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblTapMaxDistanceValue->Text = trackTapMaxDistance->Value.ToString();
         }
private: System::Void trackInertialScrollDuration_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblInertialScrollDurationValue->Text = trackInertialScrollDuration->Value.ToString();
         }
private: System::Void frmSettings_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
         {
             UpdateConfigurations();
             e->Cancel = true;
             this->Hide();
         }
private: System::Void trackTapMaxWThreshold_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblTapMaxWThresholdValue->Text = trackTapMaxWThreshold->Value.ToString();
         }
private: System::Void trackTapMaxZThreshold_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblTapMaxZThresholdValue->Text = trackTapMaxZThreshold->Value.ToString();
         }
private: System::Void trackScrollMaxZThreshold_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblScrollMaxZThresholdValue->Text = trackScrollMaxZThreshold->Value.ToString();
         }
private: System::Void btnApply_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             UpdateConfigurations();
         }
private: System::Void chkStartWithWindows_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void chkAcceleration_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void cboEasingAlgorithm_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void cboOneFinger_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void cboTwoFinger_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void cboThreeFinger_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void btnPacketObserver_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             fPacketObserverForm->Show();
             fPacketObserverForm->Activate();
         }
private: System::Void trackDeltaRatioThreshold_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblDeltaRatioThresholdValue->Text = trackDeltaRatioThreshold->Value.ToString();
         }
private: System::Void cboLeftRightPair_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             if (cboLeftRightPair->SelectedIndex == 0)
             {
                 cboLeft->Enabled = true;
                 cboRight->Enabled = true;
             }
             else
             {
                 cboLeft->Enabled = false;
                 cboRight->Enabled = false;
             }
         }
private: System::Void cboUpDownPair_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             if (cboUpDownPair->SelectedIndex == 0)
             {
                 cboUp->Enabled = true;
                 cboDown->Enabled = true;
             }
             else
             {
                 cboUp->Enabled = false;
                 cboDown->Enabled = false;
             }
         }
private: System::Void cboLeft_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void cboRight_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void cboUp_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void cboDown_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
         }
private: System::Void trackLeftRightTriggerDistance_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblLeftRightTriggerDistanceValue->Text = trackLeftRightTriggerDistance->Value.ToString() + "%";
         }
private: System::Void trackUpDownTriggerDistance_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
         {
             enableButtons();
             lblUpDownTriggerDistanceValue->Text = trackUpDownTriggerDistance->Value.ToString() + "%";
         }
private: System::Void chkReverseScroll_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 enableButtons();
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 enableButtons();
			 if(chkDisableScrolling->Checked)
				 disableScrolling();
			 else
				 enableScrolling();
		 }
};
}

