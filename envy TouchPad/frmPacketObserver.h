#pragma once

#include "PacketObserver.h"

namespace envyTouchPad 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPacketObserver
	/// </summary>
    public ref class frmPacketObserver : public System::Windows::Forms::Form, public PacketObserver
	{
	public:
		frmPacketObserver(void)
		{
			InitializeComponent();
            setObserve(false);
            reset();
		}

    public:
        virtual void update(Packet^ packet)
        {
            if (!fShouldObserve)
            {
                return;
            }

            lblWValue->Text = packet->getW().ToString();
            lblXValue->Text = packet->getX().ToString();
            lblYValue->Text = packet->getY().ToString();
            lblZValue->Text = packet->getZ().ToString();

            lblDeltaXValue->Text = packet->getDeltaX().ToString();
            lblDeltaYValue->Text = packet->getDeltaY().ToString();

            updateMaxValues(packet->getW(), packet->getZ());
            updateMaxLabels();

            lblNumberOfFingersValue->Text = packet->getCurrentNumberOfFingers().ToString();
            chkFingerPresent->Checked = packet->isFingerPresent();
            chkFingerInMotion->Checked = packet->isFingerInMotion();

            chkPhysicalButtonPressed->Checked = packet->isAnyPhysicalButtonPressed();
        }

    private:
        void disableAndHide()
        {
            this->Hide();
            setObserve(false);
            reset();
        }

        void setObserve(bool shouldObserve)
        {
            if (shouldObserve != fShouldObserve)
            {
                fShouldObserve = shouldObserve;
                if (fShouldObserve)
                {
                    btnToggleObserver->Text = "&Stop";
                }
                else
                {
                    btnToggleObserver->Text = "&Observe";
                }
            }
        }

        void reset()
        {
            fMaxW = 0;
            fMaxZ = 0;
            updateMaxLabels();

            lblWValue->Text = "0";
            lblXValue->Text = "0";
            lblYValue->Text = "0";
            lblZValue->Text = "0";

            lblNumberOfFingersValue->Text = "0";
            chkFingerPresent->Checked = false;
            chkFingerInMotion->Checked = false;
            
            chkPhysicalButtonPressed->Checked = false;
        }

        void updateMaxValues(long w, long z)
        {
            fMaxW = (w > fMaxW) ? w : fMaxW;
            fMaxZ = (z > fMaxZ) ? z : fMaxZ;
        }

        void updateMaxLabels()
        {
            {
                String^ value = fMaxW.ToString();
                if (!lblMaxWValue->Text->Equals(value))
                {
                    lblMaxWValue->Text = value;
                }
            }
            {
                String^ value = fMaxZ.ToString();
                if (!lblMaxZValue->Text->Equals(value))
                {
                    lblMaxZValue->Text = value;
                }
            }
        }

        bool fShouldObserve;
        long fMaxW;
        long fMaxZ;


    private: System::Windows::Forms::Label^  lblMaxZValue;

    private: System::Windows::Forms::Label^  label11;
    private: System::Windows::Forms::Label^  lblMaxWValue;
    private: System::Windows::Forms::Label^  label9;
    private: System::Windows::Forms::Label^  lblZValue;

    private: System::Windows::Forms::Label^  label7;
    private: System::Windows::Forms::Label^  lblYValue;

    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::Label^  lblXValue;

    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::GroupBox^  groupBox2;
    private: System::Windows::Forms::Label^  lblNumberOfFingersValue;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::CheckBox^  chkFingerInMotion;
    private: System::Windows::Forms::CheckBox^  chkFingerPresent;
private: System::Windows::Forms::CheckBox^  chkPhysicalButtonPressed;
private: System::Windows::Forms::Label^  lblDeltaYValue;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  lblDeltaXValue;
private: System::Windows::Forms::Label^  label6;

    private: System::Windows::Forms::Button^  btnReset;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPacketObserver()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::Label^  lblWValue;

    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Button^  btnClose;
    private: System::Windows::Forms::Button^  btnToggleObserver;

    protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->lblMaxZValue = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->lblMaxWValue = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->lblZValue = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->lblYValue = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->lblXValue = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->lblWValue = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->btnClose = (gcnew System::Windows::Forms::Button());
            this->btnToggleObserver = (gcnew System::Windows::Forms::Button());
            this->btnReset = (gcnew System::Windows::Forms::Button());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->lblNumberOfFingersValue = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->chkFingerInMotion = (gcnew System::Windows::Forms::CheckBox());
            this->chkFingerPresent = (gcnew System::Windows::Forms::CheckBox());
            this->chkPhysicalButtonPressed = (gcnew System::Windows::Forms::CheckBox());
            this->lblDeltaXValue = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->lblDeltaYValue = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->SuspendLayout();
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->lblDeltaYValue);
            this->groupBox1->Controls->Add(this->label8);
            this->groupBox1->Controls->Add(this->lblDeltaXValue);
            this->groupBox1->Controls->Add(this->label6);
            this->groupBox1->Controls->Add(this->lblMaxZValue);
            this->groupBox1->Controls->Add(this->label11);
            this->groupBox1->Controls->Add(this->lblMaxWValue);
            this->groupBox1->Controls->Add(this->label9);
            this->groupBox1->Controls->Add(this->lblZValue);
            this->groupBox1->Controls->Add(this->label7);
            this->groupBox1->Controls->Add(this->lblYValue);
            this->groupBox1->Controls->Add(this->label5);
            this->groupBox1->Controls->Add(this->lblXValue);
            this->groupBox1->Controls->Add(this->label3);
            this->groupBox1->Controls->Add(this->lblWValue);
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Location = System::Drawing::Point(12, 12);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(177, 81);
            this->groupBox1->TabIndex = 0;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Data";
            // 
            // lblMaxZValue
            // 
            this->lblMaxZValue->AutoSize = true;
            this->lblMaxZValue->Location = System::Drawing::Point(139, 55);
            this->lblMaxZValue->Name = L"lblMaxZValue";
            this->lblMaxZValue->Size = System::Drawing::Size(13, 13);
            this->lblMaxZValue->TabIndex = 11;
            this->lblMaxZValue->Text = L"0";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(89, 55);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(40, 13);
            this->label11->TabIndex = 10;
            this->label11->Text = L"Max Z:";
            // 
            // lblMaxWValue
            // 
            this->lblMaxWValue->AutoSize = true;
            this->lblMaxWValue->Location = System::Drawing::Point(139, 16);
            this->lblMaxWValue->Name = L"lblMaxWValue";
            this->lblMaxWValue->Size = System::Drawing::Size(13, 13);
            this->lblMaxWValue->TabIndex = 9;
            this->lblMaxWValue->Text = L"0";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(89, 16);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(44, 13);
            this->label9->TabIndex = 8;
            this->label9->Text = L"Max W:";
            // 
            // lblZValue
            // 
            this->lblZValue->AutoSize = true;
            this->lblZValue->Location = System::Drawing::Point(29, 55);
            this->lblZValue->Name = L"lblZValue";
            this->lblZValue->Size = System::Drawing::Size(13, 13);
            this->lblZValue->TabIndex = 7;
            this->lblZValue->Text = L"0";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(6, 55);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(17, 13);
            this->label7->TabIndex = 6;
            this->label7->Text = L"Z:";
            // 
            // lblYValue
            // 
            this->lblYValue->AutoSize = true;
            this->lblYValue->Location = System::Drawing::Point(29, 42);
            this->lblYValue->Name = L"lblYValue";
            this->lblYValue->Size = System::Drawing::Size(13, 13);
            this->lblYValue->TabIndex = 5;
            this->lblYValue->Text = L"0";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(6, 42);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(17, 13);
            this->label5->TabIndex = 4;
            this->label5->Text = L"Y:";
            // 
            // lblXValue
            // 
            this->lblXValue->AutoSize = true;
            this->lblXValue->Location = System::Drawing::Point(29, 29);
            this->lblXValue->Name = L"lblXValue";
            this->lblXValue->Size = System::Drawing::Size(13, 13);
            this->lblXValue->TabIndex = 3;
            this->lblXValue->Text = L"0";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(6, 29);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(17, 13);
            this->label3->TabIndex = 2;
            this->label3->Text = L"X:";
            // 
            // lblWValue
            // 
            this->lblWValue->AutoSize = true;
            this->lblWValue->Location = System::Drawing::Point(29, 16);
            this->lblWValue->Name = L"lblWValue";
            this->lblWValue->Size = System::Drawing::Size(13, 13);
            this->lblWValue->TabIndex = 1;
            this->lblWValue->Text = L"0";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(6, 16);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(21, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"W:";
            // 
            // btnClose
            // 
            this->btnClose->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnClose->Location = System::Drawing::Point(197, 173);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(85, 30);
            this->btnClose->TabIndex = 3;
            this->btnClose->Text = L"&Close";
            this->btnClose->UseVisualStyleBackColor = true;
            this->btnClose->Click += gcnew System::EventHandler(this, &frmPacketObserver::btnClose_Click);
            // 
            // btnToggleObserver
            // 
            this->btnToggleObserver->Location = System::Drawing::Point(197, 12);
            this->btnToggleObserver->Name = L"btnToggleObserver";
            this->btnToggleObserver->Size = System::Drawing::Size(85, 30);
            this->btnToggleObserver->TabIndex = 4;
            this->btnToggleObserver->Text = L"&Observe";
            this->btnToggleObserver->UseVisualStyleBackColor = true;
            this->btnToggleObserver->Click += gcnew System::EventHandler(this, &frmPacketObserver::btnToggleObserver_Click);
            // 
            // btnReset
            // 
            this->btnReset->Location = System::Drawing::Point(197, 48);
            this->btnReset->Name = L"btnReset";
            this->btnReset->Size = System::Drawing::Size(85, 30);
            this->btnReset->TabIndex = 6;
            this->btnReset->Text = L"&Reset";
            this->btnReset->UseVisualStyleBackColor = true;
            this->btnReset->Click += gcnew System::EventHandler(this, &frmPacketObserver::btnReset_Click);
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->lblNumberOfFingersValue);
            this->groupBox2->Controls->Add(this->label4);
            this->groupBox2->Controls->Add(this->chkFingerInMotion);
            this->groupBox2->Controls->Add(this->chkFingerPresent);
            this->groupBox2->Location = System::Drawing::Point(12, 99);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(176, 81);
            this->groupBox2->TabIndex = 7;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Fingers";
            // 
            // lblNumberOfFingersValue
            // 
            this->lblNumberOfFingersValue->AutoSize = true;
            this->lblNumberOfFingersValue->Location = System::Drawing::Point(105, 16);
            this->lblNumberOfFingersValue->Name = L"lblNumberOfFingersValue";
            this->lblNumberOfFingersValue->Size = System::Drawing::Size(13, 13);
            this->lblNumberOfFingersValue->TabIndex = 10;
            this->lblNumberOfFingersValue->Text = L"0";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(6, 16);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(93, 13);
            this->label4->TabIndex = 9;
            this->label4->Text = L"Number of fingers:";
            // 
            // chkFingerInMotion
            // 
            this->chkFingerInMotion->AutoSize = true;
            this->chkFingerInMotion->Location = System::Drawing::Point(9, 55);
            this->chkFingerInMotion->Name = L"chkFingerInMotion";
            this->chkFingerInMotion->Size = System::Drawing::Size(100, 17);
            this->chkFingerInMotion->TabIndex = 8;
            this->chkFingerInMotion->Text = L"Finger in motion";
            this->chkFingerInMotion->UseVisualStyleBackColor = true;
            // 
            // chkFingerPresent
            // 
            this->chkFingerPresent->AutoSize = true;
            this->chkFingerPresent->Location = System::Drawing::Point(9, 32);
            this->chkFingerPresent->Name = L"chkFingerPresent";
            this->chkFingerPresent->Size = System::Drawing::Size(93, 17);
            this->chkFingerPresent->TabIndex = 7;
            this->chkFingerPresent->Text = L"Finger present";
            this->chkFingerPresent->UseVisualStyleBackColor = true;
            // 
            // chkPhysicalButtonPressed
            // 
            this->chkPhysicalButtonPressed->AutoSize = true;
            this->chkPhysicalButtonPressed->Location = System::Drawing::Point(12, 186);
            this->chkPhysicalButtonPressed->Name = L"chkPhysicalButtonPressed";
            this->chkPhysicalButtonPressed->Size = System::Drawing::Size(138, 17);
            this->chkPhysicalButtonPressed->TabIndex = 8;
            this->chkPhysicalButtonPressed->Text = L"Physical button pressed";
            this->chkPhysicalButtonPressed->UseVisualStyleBackColor = true;
            // 
            // lblDeltaXValue
            // 
            this->lblDeltaXValue->AutoSize = true;
            this->lblDeltaXValue->Location = System::Drawing::Point(139, 29);
            this->lblDeltaXValue->Name = L"lblDeltaXValue";
            this->lblDeltaXValue->Size = System::Drawing::Size(13, 13);
            this->lblDeltaXValue->TabIndex = 13;
            this->lblDeltaXValue->Text = L"0";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(89, 29);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(45, 13);
            this->label6->TabIndex = 12;
            this->label6->Text = L"Delta X:";
            // 
            // lblDeltaYValue
            // 
            this->lblDeltaYValue->AutoSize = true;
            this->lblDeltaYValue->Location = System::Drawing::Point(139, 42);
            this->lblDeltaYValue->Name = L"lblDeltaYValue";
            this->lblDeltaYValue->Size = System::Drawing::Size(13, 13);
            this->lblDeltaYValue->TabIndex = 15;
            this->lblDeltaYValue->Text = L"0";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(89, 42);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(45, 13);
            this->label8->TabIndex = 14;
            this->label8->Text = L"Delta Y:";
            // 
            // frmPacketObserver
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(294, 212);
            this->Controls->Add(this->chkPhysicalButtonPressed);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->btnReset);
            this->Controls->Add(this->btnToggleObserver);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->groupBox1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"frmPacketObserver";
            this->Text = L"Packet Observer";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmPacketObserver::frmPacketObserver_FormClosing);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void frmPacketObserver_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
             {
                e->Cancel = true;
                disableAndHide();
             }
    private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) 
             {
                 disableAndHide();
             }
    private: System::Void btnToggleObserver_Click(System::Object^  sender, System::EventArgs^  e) 
             {
                 setObserve(!fShouldObserve);
             }
    private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) 
             {
                 reset();
             }
};
}
