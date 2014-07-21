#pragma once
#include "stdafx.h"
#include "MotorControl.h"
#include "Marking.h"
#include "FileIO.h"
#include "function.h"
#include <cv.h>
#include "cxcore.h"
#include "highgui.h"
#include "OpenCV.h"
#include "PlaneCorrection.h"
#include "Angelo.h"
#include "AngeloRTVErrorCode.h"
#include "Type_def.h"


//CMotorControl g_Motor[2];
vector<_MarkInfo> Mark;
vector<_MarkInfo> Target;
float pixelSize;
CPlaneCorrection G_Plane;
double dis_CCD2Laser_X, dis_CCD2Laser_Y;
double G_LaserScaleX, G_LaserScaleY;
cv::Mat showImg;
int G_thresh;
int showLine;
double G_mOx, G_mOy;



namespace LaserMarking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	cv::VideoCapture cap;

	/// <summary>
	/// Main 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox_Camera;
	protected: 

	private: System::Windows::Forms::Button^  bPN;
	private: System::Windows::Forms::Label^  lPN;
	private: System::Windows::Forms::Label^  lPNt;
	private: System::Windows::Forms::DataGridView^  DGVMarkInfo;









	private: System::Windows::Forms::Button^  bStartMarking;
	private: System::Windows::Forms::Button^  bSetMark;
	private: System::Windows::Forms::Button^  bAddMark;
	private: System::Windows::Forms::Button^  bRemoveMark;
	private: System::Windows::Forms::Button^  bLoadSetting;
	private: AxSAMLIGHT_CLIENT_CTRL_OCXLib::AxScSamlightClientCtrl^  m_samlight;
	private: System::Windows::Forms::Timer^  timer_CameraCapture;

	private: System::Windows::Forms::PictureBox^  pictureBox_FactoryZone;
	private: System::Windows::Forms::TabPage^  tabPage_FactoryZone;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  tLaserScaleX;
	private: System::Windows::Forms::TextBox^  tLaserScaleY;
	private: System::Windows::Forms::TextBox^  tAcc_Dec;
	private: System::Windows::Forms::TextBox^  tMoterIndex;
	private: System::Windows::Forms::TextBox^  tMaxVel;
	private: System::Windows::Forms::TextBox^  tORIGINAL_Y;
	private: System::Windows::Forms::TextBox^  tORIGINAL_X;
	private: System::Windows::Forms::Button^  bLaserScale;
	private: System::Windows::Forms::Button^  bShowLine;

	private: System::Windows::Forms::Button^  bCameraCalibration;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  bSetVelProfile;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  bLaserCalibration;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  bPixelSize;
	private: System::Windows::Forms::Button^  bGetCameraOriginal;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  bSetOriginal;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TabPage^  tabPage_ErrorMsg;
	private: System::Windows::Forms::DataGridView^  DGVErrorMsg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tErrorMsg;
	private: System::Windows::Forms::TabPage^  tabPage_Setting;
	private: System::Windows::Forms::Button^  bTake_PIC;
	private: System::Windows::Forms::TextBox^  tY_Distance;
	private: System::Windows::Forms::TextBox^  tX_Distance;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  bMove_Y;
	private: System::Windows::Forms::Label^  lX_Pos;
	private: System::Windows::Forms::Button^  bGoHome;
	private: System::Windows::Forms::Button^  bMove_X;
	private: System::Windows::Forms::Label^  lY_Pos;
	private: System::Windows::Forms::Button^  bGetPos;
	private: System::Windows::Forms::Button^  bMove_total;
	private: System::Windows::Forms::Button^  bThreshold;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tBoardLength;
	private: System::Windows::Forms::TextBox^  tBoardWidth;
	private: System::Windows::Forms::Timer^  timer_GetPos;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  rLaser;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rContent;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rDisToEdgeX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rDisToEdgeY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rMarkLength;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rMarkWidth;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  rAngle;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->pictureBox_Camera = (gcnew System::Windows::Forms::PictureBox());
			this->bPN = (gcnew System::Windows::Forms::Button());
			this->lPN = (gcnew System::Windows::Forms::Label());
			this->lPNt = (gcnew System::Windows::Forms::Label());
			this->DGVMarkInfo = (gcnew System::Windows::Forms::DataGridView());
			this->rLaser = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->rName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rContent = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rDisToEdgeX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rDisToEdgeY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rMarkLength = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rMarkWidth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rAngle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bStartMarking = (gcnew System::Windows::Forms::Button());
			this->bSetMark = (gcnew System::Windows::Forms::Button());
			this->bAddMark = (gcnew System::Windows::Forms::Button());
			this->bRemoveMark = (gcnew System::Windows::Forms::Button());
			this->bLoadSetting = (gcnew System::Windows::Forms::Button());
			this->m_samlight = (gcnew AxSAMLIGHT_CLIENT_CTRL_OCXLib::AxScSamlightClientCtrl());
			this->timer_CameraCapture = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox_FactoryZone = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage_FactoryZone = (gcnew System::Windows::Forms::TabPage());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->tLaserScaleX = (gcnew System::Windows::Forms::TextBox());
			this->tLaserScaleY = (gcnew System::Windows::Forms::TextBox());
			this->tAcc_Dec = (gcnew System::Windows::Forms::TextBox());
			this->tMoterIndex = (gcnew System::Windows::Forms::TextBox());
			this->tMaxVel = (gcnew System::Windows::Forms::TextBox());
			this->tORIGINAL_Y = (gcnew System::Windows::Forms::TextBox());
			this->tORIGINAL_X = (gcnew System::Windows::Forms::TextBox());
			this->bLaserScale = (gcnew System::Windows::Forms::Button());
			this->bShowLine = (gcnew System::Windows::Forms::Button());
			this->bCameraCalibration = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->bSetVelProfile = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bLaserCalibration = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->bPixelSize = (gcnew System::Windows::Forms::Button());
			this->bGetCameraOriginal = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->bSetOriginal = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tabPage_ErrorMsg = (gcnew System::Windows::Forms::TabPage());
			this->DGVErrorMsg = (gcnew System::Windows::Forms::DataGridView());
			this->tTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tErrorMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage_Setting = (gcnew System::Windows::Forms::TabPage());
			this->bTake_PIC = (gcnew System::Windows::Forms::Button());
			this->tY_Distance = (gcnew System::Windows::Forms::TextBox());
			this->tX_Distance = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->bMove_Y = (gcnew System::Windows::Forms::Button());
			this->lX_Pos = (gcnew System::Windows::Forms::Label());
			this->bGoHome = (gcnew System::Windows::Forms::Button());
			this->bMove_X = (gcnew System::Windows::Forms::Button());
			this->lY_Pos = (gcnew System::Windows::Forms::Label());
			this->bGetPos = (gcnew System::Windows::Forms::Button());
			this->bMove_total = (gcnew System::Windows::Forms::Button());
			this->bThreshold = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tBoardLength = (gcnew System::Windows::Forms::TextBox());
			this->tBoardWidth = (gcnew System::Windows::Forms::TextBox());
			this->timer_GetPos = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Camera))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGVMarkInfo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_samlight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_FactoryZone))->BeginInit();
			this->tabPage_FactoryZone->SuspendLayout();
			this->tabPage_ErrorMsg->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGVErrorMsg))->BeginInit();
			this->tabPage_Setting->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox_Camera
			// 
			this->pictureBox_Camera->Location = System::Drawing::Point(12, 12);
			this->pictureBox_Camera->Name = L"pictureBox_Camera";
			this->pictureBox_Camera->Size = System::Drawing::Size(640, 480);
			this->pictureBox_Camera->TabIndex = 0;
			this->pictureBox_Camera->TabStop = false;
			// 
			// bPN
			// 
			this->bPN->BackColor = System::Drawing::Color::Aqua;
			this->bPN->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bPN->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bPN->ForeColor = System::Drawing::Color::Blue;
			this->bPN->Location = System::Drawing::Point(1028, 20);
			this->bPN->Name = L"bPN";
			this->bPN->Size = System::Drawing::Size(132, 41);
			this->bPN->TabIndex = 83;
			this->bPN->Text = L"Change P/N";
			this->bPN->UseVisualStyleBackColor = false;
			// 
			// lPN
			// 
			this->lPN->AutoSize = true;
			this->lPN->BackColor = System::Drawing::Color::Navy;
			this->lPN->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lPN->ForeColor = System::Drawing::Color::Yellow;
			this->lPN->Location = System::Drawing::Point(745, 32);
			this->lPN->Name = L"lPN";
			this->lPN->Size = System::Drawing::Size(59, 29);
			this->lPN->TabIndex = 82;
			this->lPN->Text = L"test";
			// 
			// lPNt
			// 
			this->lPNt->AutoSize = true;
			this->lPNt->BackColor = System::Drawing::Color::Navy;
			this->lPNt->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lPNt->ForeColor = System::Drawing::Color::Yellow;
			this->lPNt->Location = System::Drawing::Point(666, 32);
			this->lPNt->Name = L"lPNt";
			this->lPNt->Size = System::Drawing::Size(94, 29);
			this->lPNt->TabIndex = 81;
			this->lPNt->Text = L"P/N： ";
			// 
			// DGVMarkInfo
			// 
			this->DGVMarkInfo->AllowUserToAddRows = false;
			this->DGVMarkInfo->AllowUserToDeleteRows = false;
			this->DGVMarkInfo->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->DGVMarkInfo->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->DGVMarkInfo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVMarkInfo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->rLaser, this->rName, 
				this->rContent, this->rDisToEdgeX, this->rDisToEdgeY, this->rMarkLength, this->rMarkWidth, this->rAngle});
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->DGVMarkInfo->DefaultCellStyle = dataGridViewCellStyle9;
			this->DGVMarkInfo->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->DGVMarkInfo->Location = System::Drawing::Point(658, 120);
			this->DGVMarkInfo->Name = L"DGVMarkInfo";
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle10->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->DGVMarkInfo->RowHeadersDefaultCellStyle = dataGridViewCellStyle10;
			this->DGVMarkInfo->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->DGVMarkInfo->RowsDefaultCellStyle = dataGridViewCellStyle11;
			this->DGVMarkInfo->RowTemplate->Height = 24;
			this->DGVMarkInfo->Size = System::Drawing::Size(705, 356);
			this->DGVMarkInfo->TabIndex = 76;
			// 
			// rLaser
			// 
			this->rLaser->HeaderText = L"Laser";
			this->rLaser->Name = L"rLaser";
			this->rLaser->Width = 60;
			// 
			// rName
			// 
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rName->DefaultCellStyle = dataGridViewCellStyle2;
			this->rName->HeaderText = L"MarkName";
			this->rName->Name = L"rName";
			this->rName->Width = 130;
			// 
			// rContent
			// 
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rContent->DefaultCellStyle = dataGridViewCellStyle3;
			this->rContent->HeaderText = L"Content";
			this->rContent->Name = L"rContent";
			this->rContent->Width = 250;
			// 
			// rDisToEdgeX
			// 
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rDisToEdgeX->DefaultCellStyle = dataGridViewCellStyle4;
			this->rDisToEdgeX->HeaderText = L"DisToEdge-X";
			this->rDisToEdgeX->Name = L"rDisToEdgeX";
			this->rDisToEdgeX->Width = 150;
			// 
			// rDisToEdgeY
			// 
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rDisToEdgeY->DefaultCellStyle = dataGridViewCellStyle5;
			this->rDisToEdgeY->HeaderText = L"DisToEdge-Y";
			this->rDisToEdgeY->Name = L"rDisToEdgeY";
			this->rDisToEdgeY->Width = 150;
			// 
			// rMarkLength
			// 
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rMarkLength->DefaultCellStyle = dataGridViewCellStyle6;
			this->rMarkLength->HeaderText = L"MarkLength";
			this->rMarkLength->Name = L"rMarkLength";
			this->rMarkLength->Width = 130;
			// 
			// rMarkWidth
			// 
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rMarkWidth->DefaultCellStyle = dataGridViewCellStyle7;
			this->rMarkWidth->HeaderText = L"MarkWidth";
			this->rMarkWidth->Name = L"rMarkWidth";
			this->rMarkWidth->Width = 130;
			// 
			// rAngle
			// 
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rAngle->DefaultCellStyle = dataGridViewCellStyle8;
			this->rAngle->HeaderText = L"Angle";
			this->rAngle->Name = L"rAngle";
			this->rAngle->Width = 130;
			// 
			// bStartMarking
			// 
			this->bStartMarking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->bStartMarking->Font = (gcnew System::Drawing::Font(L"Tahoma", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bStartMarking->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bStartMarking->Location = System::Drawing::Point(858, 678);
			this->bStartMarking->Name = L"bStartMarking";
			this->bStartMarking->Size = System::Drawing::Size(273, 90);
			this->bStartMarking->TabIndex = 75;
			this->bStartMarking->Text = L"Start Work";
			this->bStartMarking->UseVisualStyleBackColor = false;
			this->bStartMarking->Click += gcnew System::EventHandler(this, &Main::bStartMarking_Click);
			// 
			// bSetMark
			// 
			this->bSetMark->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->bSetMark->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bSetMark->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bSetMark->ForeColor = System::Drawing::Color::Maroon;
			this->bSetMark->Location = System::Drawing::Point(697, 494);
			this->bSetMark->Name = L"bSetMark";
			this->bSetMark->Size = System::Drawing::Size(200, 80);
			this->bSetMark->TabIndex = 77;
			this->bSetMark->Text = L"Save Setting";
			this->bSetMark->UseVisualStyleBackColor = false;
			this->bSetMark->Click += gcnew System::EventHandler(this, &Main::bSetMark_Click);
			// 
			// bAddMark
			// 
			this->bAddMark->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bAddMark->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bAddMark->ForeColor = System::Drawing::Color::Blue;
			this->bAddMark->Location = System::Drawing::Point(1081, 494);
			this->bAddMark->Name = L"bAddMark";
			this->bAddMark->Size = System::Drawing::Size(200, 80);
			this->bAddMark->TabIndex = 78;
			this->bAddMark->Text = L"Add Mark";
			this->bAddMark->UseVisualStyleBackColor = false;
			this->bAddMark->Click += gcnew System::EventHandler(this, &Main::bAddMark_Click);
			// 
			// bRemoveMark
			// 
			this->bRemoveMark->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bRemoveMark->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bRemoveMark->ForeColor = System::Drawing::Color::Blue;
			this->bRemoveMark->Location = System::Drawing::Point(1081, 592);
			this->bRemoveMark->Name = L"bRemoveMark";
			this->bRemoveMark->Size = System::Drawing::Size(200, 80);
			this->bRemoveMark->TabIndex = 79;
			this->bRemoveMark->Text = L"Remove Mark";
			this->bRemoveMark->UseVisualStyleBackColor = false;
			this->bRemoveMark->Click += gcnew System::EventHandler(this, &Main::bRemoveMark_Click);
			// 
			// bLoadSetting
			// 
			this->bLoadSetting->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->bLoadSetting->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bLoadSetting->ForeColor = System::Drawing::Color::Maroon;
			this->bLoadSetting->Location = System::Drawing::Point(697, 592);
			this->bLoadSetting->Name = L"bLoadSetting";
			this->bLoadSetting->Size = System::Drawing::Size(200, 80);
			this->bLoadSetting->TabIndex = 80;
			this->bLoadSetting->Text = L"Load Setting";
			this->bLoadSetting->UseVisualStyleBackColor = false;
			this->bLoadSetting->Click += gcnew System::EventHandler(this, &Main::bLoadSetting_Click);
			// 
			// m_samlight
			// 
			this->m_samlight->Enabled = true;
			this->m_samlight->Location = System::Drawing::Point(374, 145);
			this->m_samlight->Name = L"m_samlight";
			this->m_samlight->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^  >(resources->GetObject(L"m_samlight.OcxState")));
			this->m_samlight->Size = System::Drawing::Size(100, 50);
			this->m_samlight->TabIndex = 84;
			this->m_samlight->Visible = false;
			// 
			// timer_CameraCapture
			// 
			this->timer_CameraCapture->Tick += gcnew System::EventHandler(this, &Main::timer_CameraCapture_Tick);
			// 
			// pictureBox_FactoryZone
			// 
			this->pictureBox_FactoryZone->Location = System::Drawing::Point(156, 534);
			this->pictureBox_FactoryZone->Name = L"pictureBox_FactoryZone";
			this->pictureBox_FactoryZone->Size = System::Drawing::Size(86, 28);
			this->pictureBox_FactoryZone->TabIndex = 98;
			this->pictureBox_FactoryZone->TabStop = false;
			// 
			// tabPage_FactoryZone
			// 
			this->tabPage_FactoryZone->BackColor = System::Drawing::Color::Navy;
			this->tabPage_FactoryZone->Controls->Add(this->label23);
			this->tabPage_FactoryZone->Controls->Add(this->label24);
			this->tabPage_FactoryZone->Controls->Add(this->tLaserScaleX);
			this->tabPage_FactoryZone->Controls->Add(this->tLaserScaleY);
			this->tabPage_FactoryZone->Controls->Add(this->tAcc_Dec);
			this->tabPage_FactoryZone->Controls->Add(this->tMoterIndex);
			this->tabPage_FactoryZone->Controls->Add(this->m_samlight);
			this->tabPage_FactoryZone->Controls->Add(this->tMaxVel);
			this->tabPage_FactoryZone->Controls->Add(this->tORIGINAL_Y);
			this->tabPage_FactoryZone->Controls->Add(this->tORIGINAL_X);
			this->tabPage_FactoryZone->Controls->Add(this->bLaserScale);
			this->tabPage_FactoryZone->Controls->Add(this->bShowLine);
			this->tabPage_FactoryZone->Controls->Add(this->bCameraCalibration);
			this->tabPage_FactoryZone->Controls->Add(this->label5);
			this->tabPage_FactoryZone->Controls->Add(this->bSetVelProfile);
			this->tabPage_FactoryZone->Controls->Add(this->label4);
			this->tabPage_FactoryZone->Controls->Add(this->bLaserCalibration);
			this->tabPage_FactoryZone->Controls->Add(this->label3);
			this->tabPage_FactoryZone->Controls->Add(this->bPixelSize);
			this->tabPage_FactoryZone->Controls->Add(this->bGetCameraOriginal);
			this->tabPage_FactoryZone->Controls->Add(this->label8);
			this->tabPage_FactoryZone->Controls->Add(this->bSetOriginal);
			this->tabPage_FactoryZone->Controls->Add(this->label9);
			this->tabPage_FactoryZone->Location = System::Drawing::Point(4, 22);
			this->tabPage_FactoryZone->Name = L"tabPage_FactoryZone";
			this->tabPage_FactoryZone->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_FactoryZone->Size = System::Drawing::Size(650, 236);
			this->tabPage_FactoryZone->TabIndex = 1;
			this->tabPage_FactoryZone->Text = L"FactoryZone";
			this->tabPage_FactoryZone->UseVisualStyleBackColor = true;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->ForeColor = System::Drawing::Color::Yellow;
			this->label23->Location = System::Drawing::Point(34, 126);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(53, 12);
			this->label23->TabIndex = 91;
			this->label23->Text = L"Scalar Y";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->ForeColor = System::Drawing::Color::Yellow;
			this->label24->Location = System::Drawing::Point(34, 102);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(53, 12);
			this->label24->TabIndex = 90;
			this->label24->Text = L"Scalar X";
			// 
			// tLaserScaleX
			// 
			this->tLaserScaleX->Location = System::Drawing::Point(84, 99);
			this->tLaserScaleX->Name = L"tLaserScaleX";
			this->tLaserScaleX->Size = System::Drawing::Size(61, 21);
			this->tLaserScaleX->TabIndex = 89;
			this->tLaserScaleX->Text = L"1";
			// 
			// tLaserScaleY
			// 
			this->tLaserScaleY->Location = System::Drawing::Point(84, 123);
			this->tLaserScaleY->Name = L"tLaserScaleY";
			this->tLaserScaleY->Size = System::Drawing::Size(61, 21);
			this->tLaserScaleY->TabIndex = 88;
			this->tLaserScaleY->Text = L"1";
			// 
			// tAcc_Dec
			// 
			this->tAcc_Dec->Location = System::Drawing::Point(84, 71);
			this->tAcc_Dec->Name = L"tAcc_Dec";
			this->tAcc_Dec->Size = System::Drawing::Size(61, 21);
			this->tAcc_Dec->TabIndex = 20;
			this->tAcc_Dec->Visible = false;
			// 
			// tMoterIndex
			// 
			this->tMoterIndex->Location = System::Drawing::Point(84, 15);
			this->tMoterIndex->Name = L"tMoterIndex";
			this->tMoterIndex->Size = System::Drawing::Size(61, 21);
			this->tMoterIndex->TabIndex = 67;
			this->tMoterIndex->Visible = false;
			// 
			// tMaxVel
			// 
			this->tMaxVel->Location = System::Drawing::Point(84, 43);
			this->tMaxVel->Name = L"tMaxVel";
			this->tMaxVel->Size = System::Drawing::Size(61, 21);
			this->tMaxVel->TabIndex = 19;
			this->tMaxVel->Visible = false;
			// 
			// tORIGINAL_Y
			// 
			this->tORIGINAL_Y->Location = System::Drawing::Point(84, 180);
			this->tORIGINAL_Y->Name = L"tORIGINAL_Y";
			this->tORIGINAL_Y->Size = System::Drawing::Size(61, 21);
			this->tORIGINAL_Y->TabIndex = 36;
			this->tORIGINAL_Y->Text = L"-2591000";
			// 
			// tORIGINAL_X
			// 
			this->tORIGINAL_X->Location = System::Drawing::Point(84, 152);
			this->tORIGINAL_X->Name = L"tORIGINAL_X";
			this->tORIGINAL_X->Size = System::Drawing::Size(61, 21);
			this->tORIGINAL_X->TabIndex = 35;
			this->tORIGINAL_X->Text = L"-130000";
			// 
			// bLaserScale
			// 
			this->bLaserScale->BackColor = System::Drawing::SystemColors::Control;
			this->bLaserScale->Location = System::Drawing::Point(151, 123);
			this->bLaserScale->Name = L"bLaserScale";
			this->bLaserScale->Size = System::Drawing::Size(106, 23);
			this->bLaserScale->TabIndex = 87;
			this->bLaserScale->Text = L"Set Laser Scale";
			this->bLaserScale->UseVisualStyleBackColor = false;
			this->bLaserScale->Click += gcnew System::EventHandler(this, &Main::bLaserScale_Click);
			// 
			// bShowLine
			// 
			this->bShowLine->BackColor = System::Drawing::Color::Transparent;
			this->bShowLine->Location = System::Drawing::Point(496, 172);
			this->bShowLine->Name = L"bShowLine";
			this->bShowLine->Size = System::Drawing::Size(75, 23);
			this->bShowLine->TabIndex = 79;
			this->bShowLine->Text = L"Show Line";
			this->bShowLine->UseVisualStyleBackColor = false;
			this->bShowLine->Click += gcnew System::EventHandler(this, &Main::bShowLine_Click);
			// 
			// bCameraCalibration
			// 
			this->bCameraCalibration->BackColor = System::Drawing::Color::Transparent;
			this->bCameraCalibration->Location = System::Drawing::Point(496, 89);
			this->bCameraCalibration->Name = L"bCameraCalibration";
			this->bCameraCalibration->Size = System::Drawing::Size(140, 23);
			this->bCameraCalibration->TabIndex = 81;
			this->bCameraCalibration->Text = L"Camera Calibration";
			this->bCameraCalibration->UseVisualStyleBackColor = false;
			this->bCameraCalibration->Click += gcnew System::EventHandler(this, &Main::bCameraCalibration_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Yellow;
			this->label5->Location = System::Drawing::Point(12, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 12);
			this->label5->TabIndex = 68;
			this->label5->Text = L"Moter Index";
			this->label5->Visible = false;
			// 
			// bSetVelProfile
			// 
			this->bSetVelProfile->BackColor = System::Drawing::Color::Transparent;
			this->bSetVelProfile->Location = System::Drawing::Point(151, 13);
			this->bSetVelProfile->Name = L"bSetVelProfile";
			this->bSetVelProfile->Size = System::Drawing::Size(75, 23);
			this->bSetVelProfile->TabIndex = 24;
			this->bSetVelProfile->Text = L"SetVelProfile";
			this->bSetVelProfile->UseVisualStyleBackColor = false;
			this->bSetVelProfile->Visible = false;
			this->bSetVelProfile->Click += gcnew System::EventHandler(this, &Main::bSetVelProfile_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Yellow;
			this->label4->Location = System::Drawing::Point(12, 74);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 12);
			this->label4->TabIndex = 23;
			this->label4->Text = L"加/減速";
			this->label4->Visible = false;
			// 
			// bLaserCalibration
			// 
			this->bLaserCalibration->BackColor = System::Drawing::Color::Transparent;
			this->bLaserCalibration->Location = System::Drawing::Point(496, 123);
			this->bLaserCalibration->Name = L"bLaserCalibration";
			this->bLaserCalibration->Size = System::Drawing::Size(140, 23);
			this->bLaserCalibration->TabIndex = 78;
			this->bLaserCalibration->Text = L"Laser Calibration";
			this->bLaserCalibration->UseVisualStyleBackColor = false;
			this->bLaserCalibration->Click += gcnew System::EventHandler(this, &Main::bLaserCalibration_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Yellow;
			this->label3->Location = System::Drawing::Point(12, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 12);
			this->label3->TabIndex = 22;
			this->label3->Text = L"MaxVelocity";
			this->label3->Visible = false;
			// 
			// bPixelSize
			// 
			this->bPixelSize->BackColor = System::Drawing::Color::Transparent;
			this->bPixelSize->Location = System::Drawing::Point(496, 18);
			this->bPixelSize->Name = L"bPixelSize";
			this->bPixelSize->Size = System::Drawing::Size(140, 23);
			this->bPixelSize->TabIndex = 76;
			this->bPixelSize->Text = L"pixel size";
			this->bPixelSize->UseVisualStyleBackColor = false;
			this->bPixelSize->Click += gcnew System::EventHandler(this, &Main::bPixelSize_Click);
			// 
			// bGetCameraOriginal
			// 
			this->bGetCameraOriginal->BackColor = System::Drawing::Color::Transparent;
			this->bGetCameraOriginal->Location = System::Drawing::Point(496, 49);
			this->bGetCameraOriginal->Name = L"bGetCameraOriginal";
			this->bGetCameraOriginal->Size = System::Drawing::Size(140, 23);
			this->bGetCameraOriginal->TabIndex = 75;
			this->bGetCameraOriginal->Text = L"GetCameraOriginal";
			this->bGetCameraOriginal->UseVisualStyleBackColor = false;
			this->bGetCameraOriginal->Click += gcnew System::EventHandler(this, &Main::bGetCameraOriginal_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::Yellow;
			this->label8->Location = System::Drawing::Point(12, 155);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 12);
			this->label8->TabIndex = 37;
			this->label8->Text = L"ORIGINAL_X";
			// 
			// bSetOriginal
			// 
			this->bSetOriginal->BackColor = System::Drawing::Color::Transparent;
			this->bSetOriginal->Location = System::Drawing::Point(151, 150);
			this->bSetOriginal->Name = L"bSetOriginal";
			this->bSetOriginal->Size = System::Drawing::Size(106, 23);
			this->bSetOriginal->TabIndex = 72;
			this->bSetOriginal->Text = L"Set Original";
			this->bSetOriginal->UseVisualStyleBackColor = false;
			this->bSetOriginal->Click += gcnew System::EventHandler(this, &Main::bSetOriginal_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::Yellow;
			this->label9->Location = System::Drawing::Point(12, 183);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(65, 12);
			this->label9->TabIndex = 38;
			this->label9->Text = L"ORIGINAL_Y";
			// 
			// tabPage_ErrorMsg
			// 
			this->tabPage_ErrorMsg->Controls->Add(this->DGVErrorMsg);
			this->tabPage_ErrorMsg->Location = System::Drawing::Point(4, 22);
			this->tabPage_ErrorMsg->Name = L"tabPage_ErrorMsg";
			this->tabPage_ErrorMsg->Size = System::Drawing::Size(650, 236);
			this->tabPage_ErrorMsg->TabIndex = 2;
			this->tabPage_ErrorMsg->Text = L"Error message";
			this->tabPage_ErrorMsg->UseVisualStyleBackColor = true;
			// 
			// DGVErrorMsg
			// 
			this->DGVErrorMsg->AllowUserToAddRows = false;
			this->DGVErrorMsg->AllowUserToDeleteRows = false;
			this->DGVErrorMsg->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->DGVErrorMsg->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->tTime, this->tErrorMsg});
			this->DGVErrorMsg->Location = System::Drawing::Point(-4, 0);
			this->DGVErrorMsg->Name = L"DGVErrorMsg";
			this->DGVErrorMsg->ReadOnly = true;
			this->DGVErrorMsg->RowTemplate->Height = 24;
			this->DGVErrorMsg->Size = System::Drawing::Size(658, 240);
			this->DGVErrorMsg->TabIndex = 89;
			// 
			// tTime
			// 
			this->tTime->HeaderText = L"Time";
			this->tTime->Name = L"tTime";
			this->tTime->ReadOnly = true;
			this->tTime->Width = 150;
			// 
			// tErrorMsg
			// 
			this->tErrorMsg->HeaderText = L"Error_Message";
			this->tErrorMsg->Name = L"tErrorMsg";
			this->tErrorMsg->ReadOnly = true;
			this->tErrorMsg->Width = 460;
			// 
			// tabPage_Setting
			// 
			this->tabPage_Setting->BackColor = System::Drawing::Color::Navy;
			this->tabPage_Setting->Controls->Add(this->bTake_PIC);
			this->tabPage_Setting->Controls->Add(this->tY_Distance);
			this->tabPage_Setting->Controls->Add(this->tX_Distance);
			this->tabPage_Setting->Controls->Add(this->textBox3);
			this->tabPage_Setting->Controls->Add(this->bMove_Y);
			this->tabPage_Setting->Controls->Add(this->lX_Pos);
			this->tabPage_Setting->Controls->Add(this->bGoHome);
			this->tabPage_Setting->Controls->Add(this->bMove_X);
			this->tabPage_Setting->Controls->Add(this->lY_Pos);
			this->tabPage_Setting->Controls->Add(this->bGetPos);
			this->tabPage_Setting->Controls->Add(this->bMove_total);
			this->tabPage_Setting->Controls->Add(this->bThreshold);
			this->tabPage_Setting->Location = System::Drawing::Point(4, 22);
			this->tabPage_Setting->Name = L"tabPage_Setting";
			this->tabPage_Setting->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Setting->Size = System::Drawing::Size(650, 236);
			this->tabPage_Setting->TabIndex = 0;
			this->tabPage_Setting->Text = L"Setting";
			// 
			// bTake_PIC
			// 
			this->bTake_PIC->BackColor = System::Drawing::SystemColors::Control;
			this->bTake_PIC->Location = System::Drawing::Point(179, 166);
			this->bTake_PIC->Name = L"bTake_PIC";
			this->bTake_PIC->Size = System::Drawing::Size(100, 23);
			this->bTake_PIC->TabIndex = 86;
			this->bTake_PIC->Text = L"Take PIC";
			this->bTake_PIC->UseVisualStyleBackColor = false;
			this->bTake_PIC->Click += gcnew System::EventHandler(this, &Main::bTake_PIC_Click);
			// 
			// tY_Distance
			// 
			this->tY_Distance->Location = System::Drawing::Point(6, 40);
			this->tY_Distance->Name = L"tY_Distance";
			this->tY_Distance->Size = System::Drawing::Size(61, 21);
			this->tY_Distance->TabIndex = 13;
			this->tY_Distance->Text = L"0";
			// 
			// tX_Distance
			// 
			this->tX_Distance->Location = System::Drawing::Point(6, 12);
			this->tX_Distance->Name = L"tX_Distance";
			this->tX_Distance->Size = System::Drawing::Size(61, 21);
			this->tX_Distance->TabIndex = 12;
			this->tX_Distance->Text = L"0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(6, 106);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(61, 21);
			this->textBox3->TabIndex = 21;
			// 
			// bMove_Y
			// 
			this->bMove_Y->BackColor = System::Drawing::SystemColors::Control;
			this->bMove_Y->Location = System::Drawing::Point(73, 40);
			this->bMove_Y->Name = L"bMove_Y";
			this->bMove_Y->Size = System::Drawing::Size(75, 23);
			this->bMove_Y->TabIndex = 17;
			this->bMove_Y->Text = L"move_Y";
			this->bMove_Y->UseVisualStyleBackColor = false;
			this->bMove_Y->Click += gcnew System::EventHandler(this, &Main::bMove_Y_Click);
			// 
			// lX_Pos
			// 
			this->lX_Pos->AutoSize = true;
			this->lX_Pos->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lX_Pos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lX_Pos->ForeColor = System::Drawing::Color::Lime;
			this->lX_Pos->Location = System::Drawing::Point(304, 11);
			this->lX_Pos->Name = L"lX_Pos";
			this->lX_Pos->Size = System::Drawing::Size(61, 20);
			this->lX_Pos->TabIndex = 25;
			this->lX_Pos->Text = L"X_Pos";
			// 
			// bGoHome
			// 
			this->bGoHome->BackColor = System::Drawing::SystemColors::Control;
			this->bGoHome->Location = System::Drawing::Point(73, 166);
			this->bGoHome->Name = L"bGoHome";
			this->bGoHome->Size = System::Drawing::Size(100, 23);
			this->bGoHome->TabIndex = 82;
			this->bGoHome->Text = L"Motor Go Home";
			this->bGoHome->UseVisualStyleBackColor = false;
			this->bGoHome->Click += gcnew System::EventHandler(this, &Main::bGoHome_Click);
			// 
			// bMove_X
			// 
			this->bMove_X->BackColor = System::Drawing::SystemColors::Control;
			this->bMove_X->Location = System::Drawing::Point(73, 12);
			this->bMove_X->Name = L"bMove_X";
			this->bMove_X->Size = System::Drawing::Size(75, 23);
			this->bMove_X->TabIndex = 15;
			this->bMove_X->Text = L"move_X";
			this->bMove_X->UseVisualStyleBackColor = false;
			this->bMove_X->Click += gcnew System::EventHandler(this, &Main::bMove_X_Click);
			// 
			// lY_Pos
			// 
			this->lY_Pos->AutoSize = true;
			this->lY_Pos->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lY_Pos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lY_Pos->ForeColor = System::Drawing::Color::Lime;
			this->lY_Pos->Location = System::Drawing::Point(304, 39);
			this->lY_Pos->Name = L"lY_Pos";
			this->lY_Pos->Size = System::Drawing::Size(61, 20);
			this->lY_Pos->TabIndex = 27;
			this->lY_Pos->Text = L"Y_Pos";
			// 
			// bGetPos
			// 
			this->bGetPos->BackColor = System::Drawing::SystemColors::Control;
			this->bGetPos->Location = System::Drawing::Point(154, 41);
			this->bGetPos->Name = L"bGetPos";
			this->bGetPos->Size = System::Drawing::Size(125, 23);
			this->bGetPos->TabIndex = 28;
			this->bGetPos->Text = L"GetPos_Start";
			this->bGetPos->UseVisualStyleBackColor = false;
			this->bGetPos->Click += gcnew System::EventHandler(this, &Main::bGetPos_Click);
			// 
			// bMove_total
			// 
			this->bMove_total->BackColor = System::Drawing::SystemColors::Control;
			this->bMove_total->Location = System::Drawing::Point(154, 12);
			this->bMove_total->Name = L"bMove_total";
			this->bMove_total->Size = System::Drawing::Size(125, 23);
			this->bMove_total->TabIndex = 18;
			this->bMove_total->Text = L"move_total(ABS)";
			this->bMove_total->UseVisualStyleBackColor = false;
			this->bMove_total->Click += gcnew System::EventHandler(this, &Main::bMove_total_Click);
			// 
			// bThreshold
			// 
			this->bThreshold->BackColor = System::Drawing::SystemColors::Control;
			this->bThreshold->Location = System::Drawing::Point(73, 104);
			this->bThreshold->Name = L"bThreshold";
			this->bThreshold->Size = System::Drawing::Size(75, 23);
			this->bThreshold->TabIndex = 77;
			this->bThreshold->Text = L"Threshold";
			this->bThreshold->UseVisualStyleBackColor = false;
			this->bThreshold->Click += gcnew System::EventHandler(this, &Main::bThreshold_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage_Setting);
			this->tabControl1->Controls->Add(this->tabPage_ErrorMsg);
			this->tabControl1->Controls->Add(this->tabPage_FactoryZone);
			this->tabControl1->Location = System::Drawing::Point(12, 534);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(658, 262);
			this->tabControl1->TabIndex = 97;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Navy;
			this->label13->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Yellow;
			this->label13->Location = System::Drawing::Point(912, 81);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(110, 29);
			this->label13->TabIndex = 103;
			this->label13->Text = L"Width：";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Navy;
			this->label7->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Yellow;
			this->label7->Location = System::Drawing::Point(666, 79);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(121, 29);
			this->label7->TabIndex = 102;
			this->label7->Text = L"Length：";
			// 
			// tBoardLength
			// 
			this->tBoardLength->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tBoardLength->Location = System::Drawing::Point(793, 78);
			this->tBoardLength->Name = L"tBoardLength";
			this->tBoardLength->Size = System::Drawing::Size(100, 36);
			this->tBoardLength->TabIndex = 100;
			// 
			// tBoardWidth
			// 
			this->tBoardWidth->BackColor = System::Drawing::SystemColors::Window;
			this->tBoardWidth->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tBoardWidth->Location = System::Drawing::Point(1028, 78);
			this->tBoardWidth->Name = L"tBoardWidth";
			this->tBoardWidth->Size = System::Drawing::Size(100, 36);
			this->tBoardWidth->TabIndex = 101;
			// 
			// timer_GetPos
			// 
			this->timer_GetPos->Tick += gcnew System::EventHandler(this, &Main::timer_GetPos_Tick);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1028, 778);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tBoardLength);
			this->Controls->Add(this->tBoardWidth);
			this->Controls->Add(this->pictureBox_FactoryZone);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->bPN);
			this->Controls->Add(this->lPN);
			this->Controls->Add(this->lPNt);
			this->Controls->Add(this->DGVMarkInfo);
			this->Controls->Add(this->bStartMarking);
			this->Controls->Add(this->bSetMark);
			this->Controls->Add(this->bAddMark);
			this->Controls->Add(this->bRemoveMark);
			this->Controls->Add(this->bLoadSetting);
			this->Controls->Add(this->pictureBox_Camera);
			this->Name = L"Main";
			this->Text = L"Main";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Camera))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGVMarkInfo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_samlight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_FactoryZone))->EndInit();
			this->tabPage_FactoryZone->ResumeLayout(false);
			this->tabPage_FactoryZone->PerformLayout();
			this->tabPage_ErrorMsg->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DGVErrorMsg))->EndInit();
			this->tabPage_Setting->ResumeLayout(false);
			this->tabPage_Setting->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void AbsMotion(long axis, double inputPos, double inputSpeed){
			 m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionAxis, axis);
			 //m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionWaitForEnd, 0);

			 if(axis == 0)
				 m_samlight->ScSetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeMotionAxisPosition, G_mOx + inputPos);
			 else
				 m_samlight->ScSetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeMotionAxisPosition, G_mOy + inputPos);

			 m_samlight->ScSetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeMotionAxisSpeed, inputSpeed);
		 }

private: System::Void RelMotion(long axis, double inputPos, double inputSpeed){
			 m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionAxis, axis);
			 //m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionWaitForEnd, 0);
			 m_samlight->ScSetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeMotionAxisPositionRelative, inputPos);
			 m_samlight->ScSetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeMotionAxisSpeed, inputSpeed);
		 }

private: System::Void StartMove(int axis){
			 m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionAxis, axis);
			 m_samlight->ScExecCommand(scComSAMLightClientCtrlExecCommandMotionGo);
		 }
private: int InPosition(long axis){
			 m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionAxis, axis);
			 //m_samlight->ScExecCommand(scComSAMLightClientCtrlExecCommandMotionGo);
			 time_t t1,t2;
			 t1=time(NULL);
			 long temp;

			 while(1)
			 {
				t2=time(NULL);
				temp = m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionMoving, axis);
				if( temp == 0)
				{
					return 1;
				}
				else if( difftime(t2,t1)>10)
				{
					m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionAxis, -1);
				    m_samlight->ScExecCommand(scComSAMLightClientCtrlExecCommandMotionStopMove);
					//MessageBoxA(NULL,"馬達定位等後逾時!!", "Information", MB_OK);
					return -1;
				}
			}
		 }

private: double GetPosition(int axis){
			 m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionAxis, axis);
			 double pos = m_samlight->ScGetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeMotionAxisPosition);
			 return pos;
		 }

private: System::Int32 _25HolesCalibration(){
			 cv::Point2f C_Center(320, 240);
			 float C_Radius;
			 cv::Point2f _25Holes[25];
			 float dx, dy;
			 int count = 0;
			 //I32 ENCODEX; 			 

			 dx = 10;
			 dy = 10;				 

			 while(( dx > 1 || dy > 1 ) && count < 10)
			 {

				 RelMotion( 0, (C_Center.x-320)*pixelSize, GSpeed);
				 RelMotion(1, (C_Center.y-240)*pixelSize*(-1), GSpeed);
				 StartMove(-1);
				 Sleep(500);

				 if(InPosition(0) != 1 || InPosition(1) != 1)
				 {
					 MessageBox::Show("馬達定位等候逾時!!");
					 ErrorMessage("馬達定位等候逾時!!");
					 return 0;
				 }

				 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

				 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, 300) == 0)
				 {
					 goOriginal();		
					 MessageBox::Show("Warning, NO Mark!!");
					 ErrorMessage("Warning, NO Mark!!");
					 
					 return 0;
				 }

				 dx = C_Center.x-320;
				 dy = C_Center.y-240;

				 if(dx < 0)
					 dx = dx * (-1);
				 if(dy < 0)
					 dy = dy * (-1);
				 count ++;
			 }

			 RelMotion(0, 2, GSpeed);
			 RelMotion(1, -2, GSpeed);
			 StartMove(-1);

			 if(InPosition(0) != 1 || InPosition(1) != 1)
			 {
				 MessageBox::Show("馬達定位等候逾時!!");
				 ErrorMessage("馬達定位等候逾時!!");
				 return 0;
			 }

			 if( count == 10)
			 {
				 MessageBox::Show("Warning, fiduical mark search Fail!!");
				 ErrorMessage("fiduical mark search Fail!!");
				 return 0;
			 }
			 
			 count = 0;

			 for(int i = 0; i < 5; i++)
			 {
				 Sleep(500);
				 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

				 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, 300) == 0)
				 {
					 goOriginal();		
					 MessageBox::Show("Warning, NO Mark!!");
					 ErrorMessage("Warning, NO Mark!!");
					 return 0;
				 }

				 _25Holes[count] = C_Center;
				 count++;

				 for(int j = 0; j < 4; j++)
				 {
					 RelMotion(0, -1, GSpeed);
					 StartMove(0);

					 if(InPosition(0) != 1 || InPosition(1) != 1 )
					 {
						 MessageBox::Show("馬達定位等候逾時!!");
						 ErrorMessage("馬達定位等候逾時!!");
						 return 0;
					 }

					 Sleep(500);

					 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

					 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, 300) == 0)
					 {
						 goOriginal();		
						 MessageBox::Show("Warning, NO Mark!!");
						 ErrorMessage("Warning, NO Mark!!");
						 return 0;
					 }

					 _25Holes[count] = C_Center;
					 count++;
				 }

				 RelMotion(0, 4, GSpeed);
				 RelMotion(1, 1, GSpeed);
				 StartMove(-1);
				 if(InPosition(0) != 1 || InPosition(1) != 1)
				 {
					 MessageBox::Show("馬達定位等候逾時!!");
					 ErrorMessage("馬達定位等候逾時!!");
					 return 0;
				 }
			 }

			 G_Plane.getCCD25Holes(&_25Holes[0]);
			 G_Plane.writeCCD25Holes();

			 return 1;
		 }

private: System::Void initial_axis(){
			 GT_Open();
			 GT_Reset();
			 GT_LmtSns(255);
			 GT_HomeSns(0);
			 GT_EncSns(0);
		 }
private: System::Void ErrorMessage(String^ msg)
{
	String^ fileName;
	String^ status;
	DateTime nowTime;
	nowTime = DateTime::Now;
	status = nowTime.ToString("G")+","+msg;
	fileName = "errorlist/errorlist"+nowTime.ToString("yyyyMMdd")+".txt";
	FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
	StreamWriter^ sw=gcnew StreamWriter(fs);
	sw->WriteLine(status);
	sw->Flush();

	sw->Close();
	fs->Close();

	DGVErrorMsg->Rows->Add();
	int temp = DGVErrorMsg->RowCount-1;
	if( temp > 0)
	{
		for(int i = temp; i > 0; i--)
		{
			DGVErrorMsg->Rows[temp]->Cells[0]->Value = DGVErrorMsg->Rows[temp - 1]->Cells[0]->Value;
			DGVErrorMsg->Rows[temp]->Cells[1]->Value = DGVErrorMsg->Rows[temp - 1]->Cells[1]->Value;
		}
	}
	DGVErrorMsg->Rows[0]->Cells[0]->Value = nowTime.ToString("G");
	DGVErrorMsg->Rows[0]->Cells[1]->Value = msg;

}

private: System::Int32 FindCenterEncoder2(cv::Point2f *center){
			 cv::Point2f C_Center( 0, 0), tempCenter( 0, 0);
			 cv::Point2f Center[8];
			 cv::Point2f Compare[8];
			 float C_Radius;
			 //float dx, dy;
			 int count = 0;
			 double ENCODEX; 
			 float temp;

			 for( int i = 0; i < 8; i++)
			 {
				 Sleep(100);
				 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

				 if( getCircle(&Center[i], &C_Radius, "CameraImage.bmp", G_thresh, MarkD) == 0)
				 {
					 
					 MessageBox::Show("Warning, NO Mark!!");
					 ErrorMessage("Warning, NO Mark!!");
					 return 0;
				 }				 			 
			 }
			 for( int i = 0; i < 8; i++)
			 {
				 Compare[i].x = 0;
				 Compare[i].y = 0;
			 }

			 for( int i = 0; i < 8; i++)
			 {
				 for (int j = 0; j < 8; j++)
				 {
					 temp = Distance(Center[i], Center[j]);
					 if( temp < 5)
					 {
						 Compare[i].x = Compare[i].x + 1;
						 Compare[i].y = Compare[i].y + temp;
					 }
				 }
			 }

			 temp = 9999;
			 int index = -1;

			 for( int i = 0; i < 8; i++)
			 {
				 if( Compare[i].x >= count && Compare[i].y < temp)
				 {
					 index = i;
					 count = (int)Compare[i].x;
					 temp = Compare[i].y;
				 }
			 }

			 //int count = 0;

			 /*for( int i = 0; i < 5; i++)
			 {
				 if (Distance(tempCenter, Center[i]) < 10)
				 {
					 C_Center.x = C_Center.x + Center[i].x;
					 C_Center.y = C_Center.y + Center[i].y;
					 count++;
				 }
			 }

			 if (count < 2)
			 {
				 MessageBox::Show("機台晃動過大!!");
				 return 0;
			 }

			 C_Center.x = C_Center.x / count;
			 C_Center.y = C_Center.y / count;*/	
			 count = 0;
			 for (int i = 0; i < 8; i++)
			 {
				 if( Distance(Center[index], Center[i]) < 5)
				 {
					 tempCenter.x = tempCenter.x + Center[i].x;
					 tempCenter.y = tempCenter.y + Center[i].y;
					 count++;
				 }
			 }

			 C_Center.x = tempCenter.x/count;
			 C_Center.y = tempCenter.y/count;


			 C_Center = G_Plane.return25HolesCalibration(C_Center);

			 ENCODEX = GetPosition(0);
			 center->x = ENCODEX - C_Center.x;
			 //lX_Pos->Text = dis_CCD2Laser_X.ToString();

			 ENCODEX = GetPosition(1);
			 center->y = ENCODEX - C_Center.y;
			 //lY_Pos->Text = dis_CCD2Laser_Y.ToString();
			 return 1;
		 }

private: System::Void GetSetting()
		 {
			 pixelSize = 15;
			 dis_CCD2Laser_X = -6.01755;
			 dis_CCD2Laser_Y = 90.95763;

			 String^ file = gcnew String("setting.txt");
			 FileStream^ fs2=gcnew FileStream(file,FileMode::Open);
			 StreamReader^ sr=gcnew StreamReader(fs2);

			 tORIGINAL_X->Text = sr->ReadLine();
			 double::TryParse(tORIGINAL_X->Text, G_mOx);
			 tORIGINAL_Y->Text = sr->ReadLine();
			 double::TryParse(tORIGINAL_Y->Text, G_mOy);
			 double::TryParse(sr->ReadLine(), dis_CCD2Laser_X);
			 double::TryParse(sr->ReadLine(), dis_CCD2Laser_Y);
			 int::TryParse(sr->ReadLine(), G_thresh);
			 textBox3->Text = G_thresh.ToString();

			 G_LaserScaleX = 1;
			 G_LaserScaleY = 1;
			 lPN->Text = sr->ReadLine();
			 float::TryParse(sr->ReadLine(), pixelSize);	
			 double::TryParse(sr->ReadLine(), G_LaserScaleX);
			 double::TryParse(sr->ReadLine(), G_LaserScaleY);
			 tLaserScaleX->Text = G_LaserScaleX.ToString();
			 tLaserScaleY->Text = G_LaserScaleY.ToString();

			 sr->Close();
			 fs2->Close();

			 G_Plane.getFile_CCD25Holes();
		 }

 private: System::Void goOriginal(){
			 AbsMotion(0, 0, GSpeed);
			 AbsMotion(1, 0, GSpeed);
			 StartMove(-1);
			 //g_Motor[2].goOriginal();
			 if(InPosition(0)!=1 || InPosition(1)!=1 )
			 {
				 MessageBox::Show("Warning, Motor is NOT in position!!");
				 ErrorMessage("Warning, Motor is NOT in position!!");
				 return;
			 }
		 }

private: System::Int32 LaserMarkProcess(){
			 /*while(PLC_IO_Input(16) == 0)
			 {
				 MessageBox::Show("Please open the laser power!!");
				 ErrorMessage("The laser power does NOT open!!");
			 }*/

			 vector<_MarkInfo> tempMark;
			 
			 CMarking Markprocess(Mark, Laser_RANGE_X, Laser_RANGE_Y);
			 Markprocess.MarkingStep();
			 int step = Markprocess.returnStep();
			 double length, width;
			 _pos center;
			 String^ MarkName;
			 double moveX, moveY;


			 length = double::Parse(tBoardLength->Text);
			 width = double::Parse(tBoardWidth->Text);
			 //thickness = double::Parse(tBoardThickness->Text);

			 //g_Motor[2].SON();
			 //g_Motor[2].AbsMotion(thickness*(-1));
			 //Sleep(1000);
			 //g_Motor[2].SOFF();

			 m_samlight->ScOpticMatrixReset();
			 m_samlight->ScOpticMatrixScale(G_LaserScaleX, G_LaserScaleY);

			 for(int i = 1; i <= step; i++)
			 {
				 center = Markprocess.returnMarkInfo(i, &tempMark);
				 AbsMotion(0, center.x+dis_CCD2Laser_X, GSpeed);
				 AbsMotion(1, -center.y+dis_CCD2Laser_Y, GSpeed);
				 StartMove(-1);
				 //z = g_Motor[2].AbsMotion((tempMark[0].MarkHeight + thickness)*(-1));

				 //if(MotorError(x, y, z, 0) == 0) return 0;
		
				 if(InPosition(0)!=1 || InPosition(1)!=1 )
				 {
					 MessageBox::Show("Warning, Motor is NOT in position!!");
					 ErrorMessage("Warning, Motor is NOT in position!!!!");
					 return 0;
				 }

				 int size = tempMark.size();

				 int laser_count, status;

				 double MarkAngle;

				 for ( int j=0; j < size; j++)
				 {
					 MarkName = gcnew String((tempMark[j].Name).c_str());
					 moveX = (tempMark[j].edgeX - center.x)-(m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMinX) + m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMaxX)) / 2;
					 moveY = -(tempMark[j].edgeY - center.y)-(m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMinY) + m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMaxY)) / 2;
					 m_samlight->ScTranslateEntity(MarkName, moveX, moveY,0);

					
					 //Sleep(1000);

					 laser_count = 0;
					 status = 0;

					 if(InPosition(0)==1 && InPosition(1)==1 )
					 {

						 m_samlight->ScGetEntityDoubleData(MarkName, 71, MarkAngle);
						 m_samlight->ScRotateEntity(MarkName, (tempMark[j].edgeX - center.x), -(tempMark[j].edgeY - center.y), tempMark[j].Angle - MarkAngle);
						 status = m_samlight->ScMarkEntityByName(MarkName, 1);
						 while( status == 0 && laser_count < 5)
						 {
							 status = m_samlight->ScMarkEntityByName(MarkName, 1);
							 laser_count++;
						 }
						 //m_samlight->ScRotateEntity(MarkName, (tempMark[j].edgeX - center.x), -(tempMark[j].edgeY - center.y), tempMark[j].Angle);

						 /*if( status == 0 && laser_count == 5)
						 {
							 goOriginal();
							 _XYTable_PLC_PC_set_ALM_LV2( 3, 0, 1);
							 MessageBox::Show("Warning, laser mark fail!! Please remove the PCB!!");
							 ErrorMessage("Warning, laser mark fail!!");
							 _XYTable_PLC_PC_set_ALM_LV2( 3, 0, 0);

							 Sleep(500);

							 while( alarm(2) == 1)
							 {
								 MessageBox::Show("Warning, laser mark fail!! Please remove the PCB!!");
							     _XYTable_PLC_PC_set_ALM_LV2( 3, 0, 0);
								 Sleep(500);
							 }

							 return;
						 }*/
					 }
					 else
					 {
						 MessageBox::Show("Warning, Motor is NOT in position!!");
						 ErrorMessage("Warning, Motor is NOT in position!!!!");
						 return 0;
					 }
				 }

				 
				 for (int j=0; j < size; j++)
				 {
					 tempMark.pop_back();
				 }

				 //Sleep(2000);
	 
			 }
			 AbsMotion(0, 0, GSpeed);
			 AbsMotion(1, 0, GSpeed);
			 StartMove(-1);
			 //z = g_Motor[2].AbsMotion(thickness*(-1));

			 //if(MotorError(x, y, z, 0) == 0) return 0;


			 if(InPosition(0)!=1 || InPosition(1)!=1 )
			 {
				 MessageBox::Show("Warning, Motor is NOT in position!!");
				 ErrorMessage("Warning, Motor is NOT in position!!");
				 return 0;
			 }

			 //g_Motor[2].SOFF();
			 return 1;
			 
		 }

private: System::Int32 LaserMarkProcessWithCCD(){
			 /*while(PLC_IO_Input(16) == 0)
			 {
				 MessageBox::Show("Please open the laser power!!");
				 ErrorMessage("The laser power does NOT open!!");
			 }*/

			 /*if(PLC_IO_Input(19) == 0)
			 {
				 MessageBox::Show("The blower is overload ,and the power is shutdown!!");
			 }*/

			 vector<_MarkInfo> tempMark;
			 String^ status;
			 

			 DateTime nowTime;
		  	 nowTime = DateTime::Now;
			 String^ fileName;
				 
			 fileName = "DebugList/debug"+nowTime.ToString("yyyyMMdd")+".txt";

			 status = nowTime.ToString("G");
			 
			 
			 double length, width;
			 _pos center;
			 String^ MarkName;
			 double moveX, moveY;

			 length = double::Parse(tBoardLength->Text);
			 width = double::Parse(tBoardWidth->Text);

			 //g_Motor[2].SON();
			 //g_Motor[2].AbsMotion(thickness*(-1));
			 //Sleep(1000);
			 //g_Motor[2].SOFF();

			 cv::Point2f target_std[2], centerEncoder[2], centerCoordinate[2], original_std2act;
			 cv::Point2f vector_std, vector_act;
			 double angle_rotate, angle_std, angle_act;

			 target_std[0].x = (float)Target[0].edgeX;
			 target_std[0].y = - (float)Target[0].edgeY; //料號設定座標系與校正平面座標係之y方向相反
			 target_std[1].x = (float)Target[1].edgeX;
			 target_std[1].y = - (float)Target[1].edgeY;

			 float tempDis;
			 //cv::Point2f tempVec;


			 for (int i = 0; i < 2; i++)
			 {
				 AbsMotion(0, Target[i].edgeX, GSpeed);
				 AbsMotion(1, -Target[i].edgeY, GSpeed);
				 StartMove(-1);
				 

				 if(InPosition(0)!=1 || InPosition(1)!=1 )
				 {
					 MessageBox::Show("Warning, Motor is NOT in position!!");
					 ErrorMessage("Warning, Motor is NOT in position!!");
					 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
					 StreamWriter^ sw=gcnew StreamWriter(fs);
					 sw->WriteLine(status);
					 sw->Flush();
				 
					 sw->Close();
					 fs->Close();
					 return 0;
				 }

				 if( FindCenterEncoder2(&centerEncoder[i]) == 0)
				 {
					 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
					 StreamWriter^ sw=gcnew StreamWriter(fs);
					 sw->WriteLine(status);
					 sw->Flush();
				 
					 sw->Close();
					 fs->Close();
					 return 0;
				 }

				 //centerCoordinate[i] = G_Plane.returnCoordinate(centerEncoder[i]);
				 centerCoordinate[i].x = centerEncoder[i].x - G_mOx;
				 centerCoordinate[i].y = centerEncoder[i].y - G_mOy;
			 } 

			 

			 status = status+","+centerCoordinate[0].x.ToString()+","+centerCoordinate[0].y.ToString()+","+centerCoordinate[1].x.ToString()+","+centerCoordinate[1].y.ToString()+"," +Distance(target_std[0],target_std[1]).ToString()+"," +Distance(centerCoordinate[0],centerCoordinate[1]).ToString();

			 vector_std.x = target_std[1].x - target_std[0].x;
			 vector_std.y = target_std[1].y - target_std[0].y; 
			 vector_act.x = centerCoordinate[1].x - centerCoordinate[0].x;
			 vector_act.y = centerCoordinate[1].y - centerCoordinate[0].y;

			 angle_std = acos( vector_std.x/ sqrt(vector_std.x*vector_std.x+vector_std.y*vector_std.y));
			 angle_act = acos( vector_act.x/ sqrt(vector_act.x*vector_act.x+vector_act.y*vector_act.y));

			 if( vector_std.y < 0)
				 angle_std = angle_std*(-1);
			 if( vector_act.y < 0)
				 angle_act = angle_act*(-1);

			 angle_rotate = angle_act - angle_std;

			 status = status + "," + angle_rotate.ToString();

			 tempDis = Distance( centerCoordinate[0], centerCoordinate[1]);
			 vector_act.x = vector_act.x / tempDis;
			 vector_act.y = vector_act.y / tempDis;
			 tempDis = ( Distance(target_std[0], target_std[1]) - Distance( centerCoordinate[0], centerCoordinate[1]))/2;

			 /*靶標座標線補償*/
			 centerCoordinate[0].x = centerCoordinate[0].x - vector_act.x * tempDis;
			 centerCoordinate[0].y = centerCoordinate[0].y - vector_act.y * tempDis;
			 centerCoordinate[1].x = centerCoordinate[1].x + vector_act.x * tempDis;
			 centerCoordinate[1].y = centerCoordinate[1].y + vector_act.y * tempDis;

			 /*std原點投映至校正平面原點*/
			 cv::Point2f tempVec;
			 CoordinateRotation( target_std[0], &tempVec, angle_rotate);
			 original_std2act.x = centerCoordinate[0].x - tempVec.x;
			 original_std2act.y = centerCoordinate[0].y - tempVec.y;

			 cv::Point2f tempCenter_std, tempCenter_act, tempCenterEncoder;

			 //m_samlight->ScOpticMatrixReset();
			 //m_samlight->ScOpticMatrixScale(G_LaserScaleX, G_LaserScaleY);
			 //m_samlight->ScOpticMatrixRotate(0, 0, angle_rotate);

			 CMarking Markprocess(Mark, Laser_RANGE_X, Laser_RANGE_Y);
			 Markprocess.MarkingStep();
			 int step = Markprocess.returnStep();

			 _FitRect tempRect;
			 double tempLength, tempWidth;

			 for(int i = 1; i <= step; i++)
			 {
				 
				 center = Markprocess.returnMarkInfo(i, &tempMark, &tempRect);
				 tempCenter_std.x = (float)center.x;
				 tempCenter_std.y = - (float)center.y;
				 
				 CoordinateRotation( tempCenter_std, &tempCenter_act, angle_rotate);

				 tempCenter_act.x = tempCenter_act.x + original_std2act.x;
				 tempCenter_act.y = tempCenter_act.y + original_std2act.y;

				 //tempCenterEncoder = G_Plane.returnMotorEncoder( tempCenter_act);
				 /*if(tempMark.size() == 1)
					 tempRect = Markprocess.returnRect(tempMark[0], angle_rotate);*/
				 tempLength = tempRect.Xu - tempRect.Xl;
				 tempWidth = tempRect.Yu - tempRect.Yl;

				 if(tempMark.size() == 1 && (tempLength > Laser_RANGE_X || tempWidth > Laser_RANGE_Y))
				 {
					 //m_samlight->ScOpticMatrixRotate(0, 0, -angle_rotate);
					 double SplitRangeX, SplitRangeY;
					 m_samlight->ScSetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeHorizontalSplittingValue, 50);
					 m_samlight->ScSetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeVerticalSplittingValue, 50);

					 SplitRangeX = m_samlight->ScGetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeHorizontalSplittingValue);
					 SplitRangeY = m_samlight->ScGetDoubleValue(scComSAMLightClientCtrlDoubleValueTypeVerticalSplittingValue);

					 

					 int size = tempMark.size();

					 int laser_count, status;

					 double MarkAngle;

					 for ( int j=0; j < size; j++)
					 {
						 MarkName = gcnew String((tempMark[j].Name).c_str());

						 if(tempMark[j].content != "-")
						 {
							 String^ tempContent =  gcnew String((tempMark[j].content).c_str());
							 m_samlight->ScChangeTextByName(MarkName, tempContent);
						 }
					 
						 moveX = (tempMark[j].edgeX - center.x)-(m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMinX) + m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMaxX)) / 2;
						 moveY = -(tempMark[j].edgeY - center.y)-(m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMinY) + m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMaxY)) / 2;
						 m_samlight->ScTranslateEntity(MarkName, moveX, moveY,0);

						 m_samlight->ScGetEntityDoubleData(MarkName, 71, MarkAngle);
						 double tempAngle = tempMark[j].Angle + angle_rotate * 180 / PI - MarkAngle;						 
						 m_samlight->ScRotateEntity(MarkName, (tempMark[j].edgeX - center.x), -(tempMark[j].edgeY - center.y), tempAngle);
						 m_samlight->ScExecCommand(scComSAMLightClientCtrlExecCommandResplitJob);

						 tempLength = -m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMinX);
						 tempWidth = m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMaxY);

						 AbsMotion(0, tempCenter_act.x - (tempLength - SplitRangeX / 2) + dis_CCD2Laser_X, GSpeed);
						 AbsMotion(1, tempCenter_act.y + (tempWidth - SplitRangeY / 2) + dis_CCD2Laser_Y, GSpeed);
						 StartMove(-1);

						 laser_count = 0;

						 if(InPosition(0)==1 && InPosition(1)==1 )
						 {
							 
							 status = m_samlight->ScMarkEntityByName(MarkName, 1);
							 while( status == 0 && laser_count < 5)
							 {							 
								 status = m_samlight->ScMarkEntityByName(MarkName, 1);							 
								 laser_count++;
							 }

							 m_samlight->ScRotateEntity(MarkName, (tempMark[j].edgeX - center.x), -(tempMark[j].edgeY - center.y), -(tempMark[j].Angle + angle_rotate * 180 / PI));
							
						 }
						 else
						 {
							 MessageBox::Show("Warning, Motor is NOT in position!!");
							 ErrorMessage("Warning, Motor is NOT in position!!");
							 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
							 StreamWriter^ sw=gcnew StreamWriter(fs);
							 sw->WriteLine(status);
							 sw->Flush();
						 
							 sw->Close();
							 fs->Close();
							 return 0;
						 }
					 }

				 }
				 else
				 {
					 AbsMotion(0, tempCenter_act.x + dis_CCD2Laser_X, GSpeed);
					 AbsMotion(1, tempCenter_act.y + dis_CCD2Laser_Y, GSpeed);
					 StartMove(-1);
					 //z = g_Motor[2].AbsMotion((tempMark[0].MarkHeight + thickness)*(-1));
			
					 /*if(InPosition(0)!=1 || InPosition(1)!=1 )
					 {
						 MessageBox::Show("Warning, Motor is NOT in position!!");
						 ErrorMessage("Warning, Motor is NOT in position!!");
						 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
						 StreamWriter^ sw=gcnew StreamWriter(fs);
						 sw->WriteLine(status);
						 sw->Flush();
					 
						 sw->Close();
						 fs->Close();
						 return 0;
					 }*/

					 int size = tempMark.size();

					 int laser_count, status;

					 double MarkAngle;

					 for ( int j=0; j < size; j++)
					 {
						 MarkName = gcnew String((tempMark[j].Name).c_str());

						 if(tempMark[j].content != "-")
						 {
							 String^ tempContent =  gcnew String((tempMark[j].content).c_str());
							 m_samlight->ScChangeTextByName(MarkName, tempContent);
						 }
					 
						 moveX = (tempMark[j].edgeX - center.x)-(m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMinX) + m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMaxX)) / 2;
						 moveY = -(tempMark[j].edgeY - center.y)-(m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMinY) + m_samlight->ScGetEntityOutline(MarkName, scComSAMLightClientCtrlOutlineIndexMaxY)) / 2;
						 m_samlight->ScTranslateEntity(MarkName, moveX, moveY,0);



						 /*if(MotorError(x, y, z, 0) == 0) 
						 {
							 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
							 StreamWriter^ sw=gcnew StreamWriter(fs);
							 sw->WriteLine(status);
							 sw->Flush();
						 
							 sw->Close();
							 fs->Close();
							 return 0;
						 }*/
						 //Sleep(1000);

						 laser_count = 0;

						 if(InPosition(0)==1 && InPosition(1)==1 )
						 {
							 /*CameraImage->MemorySnapImage();
					 CameraImage->MemorySaveImage("CameraImage.bmp");*/
							 m_samlight->ScGetEntityDoubleData(MarkName, 71, MarkAngle);
							 m_samlight->ScRotateEntity(MarkName, (tempMark[j].edgeX - center.x), -(tempMark[j].edgeY - center.y), tempMark[j].Angle - MarkAngle);
							 status = m_samlight->ScMarkEntityByName(MarkName, 1);
							 while( status == 0 && laser_count < 5)
							 {							 
								 status = m_samlight->ScMarkEntityByName(MarkName, 1);							 
								 laser_count++;
							 }
							 //m_samlight->ScRotateEntity(MarkName, (tempMark[j].edgeX - center.x), -(tempMark[j].edgeY - center.y), -tempMark[j].Angle);

							 /*if( status == 0 && laser_count == 5)
							 {
								 goOriginal();
								 _XYTable_PLC_PC_set_ALM_LV2( 3, 0, 1);
								 MessageBox::Show("Warning, laser communicate fail!! Please remove the PCB!!");
								 ErrorMessage("Warning, aser communicate fail!!");
								 _XYTable_PLC_PC_set_ALM_LV2( 3, 0, 0);

								 Sleep(500);

								 while( alarm(2) == 1)
								 {
									 MessageBox::Show("Warning, laser mark fail!! Please remove the PCB!!");
									 ErrorMessage("Warning, laser mark fail!!");
									 _XYTable_PLC_PC_set_ALM_LV2( 3, 0, 0);
									 Sleep(500);
								 }

								 return 0;
							 }*/
						 }
						 else
						 {
							 MessageBox::Show("Warning, Motor is NOT in position!!");
							 ErrorMessage("Warning, Motor is NOT in position!!");
							 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
							 StreamWriter^ sw=gcnew StreamWriter(fs);
							 sw->WriteLine(status);
							 sw->Flush();
						 
							 sw->Close();
							 fs->Close();
							 return 0;
						 }
					 }
				 }

				 unsigned int size = tempMark.size();

				 
				 for (int j=0; j < size; j++)
				 {
					 tempMark.pop_back();
				 }

				 //Sleep(2000);
	 
			 }

			 //m_samlight->ScOpticMatrixRotate(0, 0, -angle_rotate);


			 /*AbsMotion(0, 0, GSpeed);
			 AbsMotion(1, 0, GSpeed);
			 StartMove(-1);
			 //z = g_Motor[2].AbsMotion(thickness*(-1))


			 if(InPosition(0)!=1 || InPosition(1)!=1 )
			 {
				 MessageBox::Show("Warning, Motor is NOT in position!!");
				 ErrorMessage("Warning, Motor is NOT in position!!");
				 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
				 StreamWriter^ sw=gcnew StreamWriter(fs);
				 sw->WriteLine(status);
				 sw->Flush();
			 
				 sw->Close();
				 fs->Close();

				 return 0;
			 }*/

			 
			 FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
			 StreamWriter^ sw=gcnew StreamWriter(fs);
			 sw->WriteLine(status);
			 sw->Flush();
		 
			 sw->Close();
			 fs->Close();

			 

			 return 1;
		 
		 }
private: System::Void LoadPN()
		 {


			 vector<_MarkInfo> tempMark, tempTarget;
			 CFileIO getMarkInfo;
			 string filename;

			 MarshalString(lPN->Text, filename);
			 getMarkInfo.getFile(filename, &tempMark, &tempTarget);
			 
			 tBoardLength->Text = (getMarkInfo.getBoardLength()).ToString();
			 tBoardWidth->Text = (getMarkInfo.getBoardWidth()).ToString();

			 Mark = tempMark;
			 Target = tempTarget;

			 DGVMarkInfo->RowCount = Target.size() + Mark.size();
			 String^ Temp;

			 for( unsigned int i = 0; i < Target.size(); i++)
			 {


				 DGVMarkInfo->Rows[i]->Cells["rLaser"]->Value = false;

				 Temp = gcnew String((Target[i].Name).c_str());
				 DGVMarkInfo->Rows[i]->Cells["rName"]->Value = Temp;

				 //temp = gcnew String((Target[i].content).c_str());
				 DGVMarkInfo->Rows[i]->Cells["rContent"]->Value = "";

				 DGVMarkInfo->Rows[i]->Cells["rDisToEdgeX"]->Value = (Target[i].edgeX).ToString();

				 DGVMarkInfo->Rows[i]->Cells["rDisToEdgeY"]->Value = (Target[i].edgeY).ToString();

				 DGVMarkInfo->Rows[i]->Cells["rMarkLength"]->Value = "";

				 DGVMarkInfo->Rows[i]->Cells["rMarkWidth"]->Value = "";

				 DGVMarkInfo->Rows[i]->Cells["rAngle"]->Value = "";
				 
			 }

			 int n = Target.size();
			 
			 for( unsigned int i = 0; i < Mark.size(); i++)
			 {

				 DGVMarkInfo->Rows[i + n]->Cells["rLaser"]->Value = Mark[i].IsLaser;

				 Temp = gcnew String((Mark[i].Name).c_str());
				 DGVMarkInfo->Rows[i + n]->Cells["rName"]->Value = Temp;

				 Temp = gcnew String((Mark[i].content).c_str());
				 DGVMarkInfo->Rows[i + n]->Cells["rContent"]->Value = Temp;

				 DGVMarkInfo->Rows[i + n]->Cells["rDisToEdgeX"]->Value = (Mark[i].edgeX).ToString();

				 DGVMarkInfo->Rows[i + n]->Cells["rDisToEdgeY"]->Value = (Mark[i].edgeY).ToString();

				 DGVMarkInfo->Rows[i + n]->Cells["rMarkLength"]->Value = (Mark[i].MarkLength).ToString();

				 DGVMarkInfo->Rows[i + n]->Cells["rMarkWidth"]->Value = (Mark[i].MarkWidth).ToString();

				 DGVMarkInfo->Rows[i + n]->Cells["rAngle"]->Value = (Mark[i].Angle).ToString();

				 
			 }



		 }


private: System::Void SavePN()
		 {
			 String^ temp;
			 String^ fileName;
			 
			 fileName = "PN/"+lPN->Text+".pn";
			 FileStream^ fs=gcnew FileStream(fileName, FileMode::Create);
			 StreamWriter^ sw=gcnew StreamWriter(fs);
			 temp = tBoardLength->Text+","+tBoardWidth->Text;
			 sw->WriteLine(temp);
			 sw->Flush();

			 for(int i = 0; i < DGVMarkInfo->RowCount; i++)
			 {
				 temp = DGVMarkInfo->Rows[i]->Cells["rLaser"]->Value+","+DGVMarkInfo->Rows[i]->Cells["rName"]->Value+","+DGVMarkInfo->Rows[i]->Cells["rContent"]->Value+","+DGVMarkInfo->Rows[i]->Cells["rDisToEdgeX"]->Value+","+DGVMarkInfo->Rows[i]->Cells["rDisToEdgeY"]->Value+","+DGVMarkInfo->Rows[i]->Cells["rMarkLength"]->Value+","+DGVMarkInfo->Rows[i]->Cells["rMarkWidth"]->Value+","+DGVMarkInfo->Rows[i]->Cells["rAngle"]->Value;
				 sw->WriteLine(temp);
				 sw->Flush();
			 }
			 sw->Close();
			 fs->Close();

			 int MarkNum = Mark.size();

			 for(int i = 0; i < MarkNum; i++)
			 {
				 Mark.pop_back();
			 }

			 /*string FileName;
			 MarshalString(fileName, FileName);
			 CFileIO getMarkInfo;
			 getMarkInfo.getFile(FileName, &Mark);
			 
			 tBoardLength->Text = (getMarkInfo.getBoardLength()).ToString();
			 tBoardWidth->Text = (getMarkInfo.getBoardWidth()).ToString();*/

			 LoadPN();
			 SetLaserMarkText();

		 }
private: System::Void SaveSetting(){

		 	 String^ fileName;
				 
			 fileName = "setting.txt";
			 FileStream^ fs=gcnew FileStream(fileName, FileMode::Create);
			 StreamWriter^ sw=gcnew StreamWriter(fs);
			 sw->WriteLine(tORIGINAL_X->Text);
			 sw->WriteLine(tORIGINAL_Y->Text);
			 sw->WriteLine(dis_CCD2Laser_X);
			 sw->WriteLine(dis_CCD2Laser_Y);
			 sw->WriteLine(G_thresh);
			 sw->WriteLine(lPN->Text);
			 sw->WriteLine(pixelSize);
			 sw->WriteLine(G_LaserScaleX);
			 sw->WriteLine(G_LaserScaleY);
			 sw->Flush();
		 
			 sw->Close();
			 fs->Close();
		 }

private: System::Void SetLaserMarkText(){
			 if(m_samlight->ScIsRunning() == 1)
			 {
				 /*while(PLC_IO_Input(16) == 0)
				 {
					 MessageBox::Show("Please open the laser power!!");
					 ErrorMessage("The laser power does NOT open!!");
				 }*/
				 String^ name;
				 String^ Text_setting;
				 double ScaleX, ScaleY;
				 for(unsigned int i = 0; i < Mark.size(); i++)
				 {
					 name = gcnew String((Mark[i].Name).c_str());

					 if( Mark[i].content != "-")
					 {
						 Text_setting = gcnew String((Mark[i].content).c_str());

						 m_samlight->ScChangeTextByName(name,Text_setting);
					 }

					 
					 if( Mark[i].MarkLength > 0 && Mark[i].MarkWidth > 0)
					 {
						 ScaleX = Mark[i].MarkLength/(m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMaxX)-m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMinX));
						 ScaleY = Mark[i].MarkWidth/(m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMaxY)-m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMinY));
					 }
					 else if( Mark[i].MarkWidth ==0 && Mark[i].MarkLength > 0)
					 {
						 ScaleX = Mark[i].MarkLength/(m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMaxX)-m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMinX));
						 ScaleY = ScaleX;
					 }
					 else if( Mark[i].MarkLength ==0 && Mark[i].MarkWidth > 0)
					 {
						 ScaleY = Mark[i].MarkWidth/(m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMaxY)-m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMinY));
						 ScaleX = ScaleY;
					 }
					 else if( Mark[i].MarkLength ==0 && Mark[i].MarkWidth == 0)
					 {
						 Mark[i].MarkLength = m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMaxX)-m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMinX);
						 Mark[i].MarkWidth = m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMaxY)-m_samlight->ScGetEntityOutline(name, scComSAMLightClientCtrlOutlineIndexMinY);
						 ScaleX = 1;
						 ScaleY = 1;

					 }
					 m_samlight->ScScaleEntity(name, ScaleX, ScaleY, 1);
				 }
			 }
		 }
private: System::Void Main_Load(System::Object^  sender, System::EventArgs^  e) {
			 GetSetting();
			 
			 //initial_axis();
			 /*for(int i = 0; i < 2; i++)
			 {
				 g_Motor[i].setParameter(i+1);
				 g_Motor[i].SON();
				 g_Motor[i].goHomeMove();
				 g_Motor[i].setVelProfile(100,1, 0.01);
			 }
			 g_Motor[0].setOriginal(int::Parse(tORIGINAL_X->Text));
			 g_Motor[1].setOriginal(int::Parse(tORIGINAL_Y->Text));*/

			 I16 result;

			 m_samlight->ScSetLongValue(scComSAMLightClientCtrlLongValueTypeMotionWaitForEnd, 1);

			 result = AngeloRTV_Initial(CCDPortNo);
			 result = AngeloRTV_Software_Reset(CCDPortNo);
			 result = AngeloRTV_Set_Color_Format(CCDPortNo, 1); //GRAY
			 result = AngeloRTV_Set_Video_Format(CCDPortNo, 0); //FULLNTSC
			 result = AngeloRTV_Capture_Start(CCDPortNo, 0xFFFFFFFF);

			 /*cap.open(0);
			 cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
			 cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);*/
			 timer_CameraCapture->Enabled = true;

			 showLine = 0;

			 LoadPN();

		 }
private: System::Void timer_CameraCapture_Tick(System::Object^  sender, System::EventArgs^  e) {
			 //cap>>showImg;
			 //cv::cvtColor(showImg, showImg, CV_BGR2GRAY);
			 I16 result;
			 result = AngeloRTV_Save_File(CCDPortNo, "camera.bmp", 1, 0);
			 showImg = cv::imread("camera.bmp", 1);

			 if(showLine == 1)
			 {
				 cv::Scalar color(0, 0, 255);

				 cv::line(showImg, cv::Point(320, 0), cv::Point(320, 480), color, 1, 8, 0);
				 cv::line(showImg, cv::Point(0, 240), cv::Point(640, 240), color, 1, 8, 0);
			 }
			 System::Drawing::Graphics^ graphics = pictureBox_Camera->CreateGraphics();
			 System::IntPtr ptr(showImg.ptr());
			 System::Drawing::Bitmap^ b  = gcnew System::Drawing::Bitmap(showImg.cols,showImg.rows,showImg.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr);
			 System::Drawing::RectangleF rect(0,0,pictureBox_Camera->Width,pictureBox_Camera->Height);
			 graphics->DrawImage(b,rect);
		 }
private: System::Void bSetMark_Click(System::Object^  sender, System::EventArgs^  e) {
			 SavePN();
		 }
private: System::Void bAddMark_Click(System::Object^  sender, System::EventArgs^  e) {
			 DGVMarkInfo->RowCount = DGVMarkInfo->RowCount+1;
			 int RowIndex = DGVMarkInfo->RowCount-1;

			 DGVMarkInfo->Rows[RowIndex]->Cells["rLaser"]->Value = false;
		 }
private: System::Void bRemoveMark_Click(System::Object^  sender, System::EventArgs^  e) {
			 if( DGVMarkInfo->SelectedRows->Count > 0 && DGVMarkInfo->SelectedRows[0]->Index != DGVMarkInfo->Rows->Count-1)
			 {
				 DGVMarkInfo->Rows->RemoveAt( DGVMarkInfo->SelectedRows[0]->Index);
			 }
			 else if(DGVMarkInfo->SelectedRows->Count > 0 && DGVMarkInfo->SelectedRows[0]->Index == DGVMarkInfo->Rows->Count-1)
			 {
				 int RowIndex = DGVMarkInfo->Rows->Count-1;

				 if( RowIndex > 0)
				 {
					 DGVMarkInfo->Rows[RowIndex]->Cells["rLaser"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rLaser"]->Value;
					 DGVMarkInfo->Rows[RowIndex]->Cells["rName"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rName"]->Value;
					 DGVMarkInfo->Rows[RowIndex]->Cells["rContent"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rContent"]->Value;
					 DGVMarkInfo->Rows[RowIndex]->Cells["rDisToEdgeX"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rDisToEdgeX"]->Value;
					 DGVMarkInfo->Rows[RowIndex]->Cells["rDisToEdgeY"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rDisToEdgeY"]->Value;
					 DGVMarkInfo->Rows[RowIndex]->Cells["rMarkLength"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rMarkLength"]->Value;
					 DGVMarkInfo->Rows[RowIndex]->Cells["rMarkWidth"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rMarkWidth"]->Value;
					 DGVMarkInfo->Rows[RowIndex]->Cells["rAngle"]->Value = DGVMarkInfo->Rows[RowIndex-1]->Cells["rAngle"]->Value;
					 DGVMarkInfo->Rows->RemoveAt( RowIndex-1);
				 }
				 else
				 {
					 DGVMarkInfo->Rows->RemoveAt( RowIndex);
				 }

			 }
		 }
private: System::Void bLoadSetting_Click(System::Object^  sender, System::EventArgs^  e) {
			 LoadPN();

			 SetLaserMarkText();

		 }
private: System::Void bStartMarking_Click(System::Object^  sender, System::EventArgs^  e) {
			 showLine = 0;
			 if( Target.size() < 2)
				 LaserMarkProcess();
			 else
				 LaserMarkProcessWithCCD();
		 }
private: System::Void bMove_X_Click(System::Object^  sender, System::EventArgs^  e) {
			 double pos;
			 if(double::TryParse(tX_Distance->Text,pos))
			 {
				 RelMotion(0, pos, GSpeed);
				 StartMove(0);
				 InPosition(0);
			 }
		 }
private: System::Void bMove_Y_Click(System::Object^  sender, System::EventArgs^  e) {
			 double pos;
			 if(double::TryParse(tY_Distance->Text,pos))
			 {
				 RelMotion(1, pos, GSpeed);
				 StartMove(1);
				 InPosition(1);
			 }
		 }
private: System::Void bMove_total_Click(System::Object^  sender, System::EventArgs^  e) {
			 double pos[2], length, width;
			 double::TryParse(tBoardLength->Text, length);
			 double::TryParse(tBoardWidth->Text, width);
			 
			 
			 //array <CMotorControl^> ^motor=gcnew array <CMotorControl^>(3);
			 //g_Motor[2].SON();

			 if(double::TryParse(tX_Distance->Text,pos[0]) && double::TryParse(tY_Distance->Text,pos[1]))
			 {
				 AbsMotion(0, pos[0], GSpeed);
				 AbsMotion(1, - pos[1], GSpeed);
				 StartMove(-1);
			 }
		 }
private: System::Void bThreshold_Click(System::Object^  sender, System::EventArgs^  e) {
			 cv::Mat Image, Image_binary;
			 int thresh = -1;

			 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);
			 Image = cv::imread("CameraImage.bmp", 0);


			 int::TryParse(textBox3->Text, thresh);
		     if( thresh >= 0 && thresh <= 255 )
			 {
				 G_thresh = thresh;
			 }
			 else if(textBox3->Text == "987")
			 {
				 pictureBox_FactoryZone->Visible = false;
				 //pictureBox_Conveyor->Visible = false;
				 textBox3->Text = G_thresh.ToString();
				 return;
			 }
			 else
			 {
				 thresh = G_thresh;
				 textBox3->Text = thresh.ToString();
				 return;

			 }

			 cv::Point2f C_Center(320,240);
			 float C_Radius;
			 //float dx, dy;

			 cv::threshold(Image, Image_binary,thresh, 255, cv::THRESH_BINARY);

			 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, MarkD) == 0)
			 {
				 cv::destroyAllWindows();
				 cv::namedWindow( "window", CV_WINDOW_AUTOSIZE );
				 cv::imshow( "window" , Image_binary);
				 MessageBox::Show("Warning, NO Mark!!");
				 ErrorMessage("Warning, NO Mark!!");
				 return ;
			 }

			 
			 cv::cvtColor(Image_binary, Image_binary,CV_GRAY2RGB, 0);
			 cv::circle(Image_binary, C_Center, C_Radius, cv::Scalar(0, 0, 255), 1);

			 cv::destroyAllWindows();
			 cv::namedWindow( "window", CV_WINDOW_AUTOSIZE );
			 cv::imshow( "window" , Image_binary);
		 }
private: System::Void bTake_PIC_Click(System::Object^  sender, System::EventArgs^  e) {
			 AngeloRTV_Save_File(CCDPortNo, "PIC.bmp", 1, 0);
		 }
private: System::Void bSetVelProfile_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bLaserScale_Click(System::Object^  sender, System::EventArgs^  e) {
			 double temp;
			 if(double::TryParse(tLaserScaleX->Text, temp) && double::TryParse(tLaserScaleY->Text, temp))
			 {
				 double::TryParse(tLaserScaleX->Text, G_LaserScaleX);
				 double::TryParse(tLaserScaleY->Text, G_LaserScaleY);
				 SaveSetting();
			 }
			 else
			 {
				 tLaserScaleX->Text = G_LaserScaleX.ToString();
				 tLaserScaleY->Text = G_LaserScaleY.ToString();
			 }
		 }
private: System::Void bSetOriginal_Click(System::Object^  sender, System::EventArgs^  e) {
			 //g_Motor[0].setOriginal(int::Parse(tORIGINAL_X->Text));
			 //g_Motor[1].setOriginal(int::Parse(tORIGINAL_Y->Text));
			 //g_Motor[2].setOriginal(I32::Parse(tORIGINAL_Z->Text));
			 double::TryParse(tORIGINAL_X->Text, G_mOx);
			 double::TryParse(tORIGINAL_Y->Text, G_mOy);

			 SaveSetting();
		 }
private: System::Void bPixelSize_Click(System::Object^  sender, System::EventArgs^  e) {
			 cv::Point2f C_Center(320,240);
			 float C_Radius;

			 cv::Point2f C1, C2, C3;

			 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

			 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, 300) == 0)
			 {
				 MessageBox::Show("Warning, NO Mark!!");
				 ErrorMessage("Warning, NO Mark!!");
				 return;
			 }

			 C1 = C_Center;

			 RelMotion(1, -4, GSpeed);
			 StartMove(1);

			 if(InPosition(0) != 1 || InPosition(1) != 1)
			 {
				 MessageBox::Show("馬達定位等候逾時!!");
				 ErrorMessage("馬達定位等候逾時!!");
				 return;
			 }

			 Sleep(500);
			 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

			 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, 300) == 0)
			 {
				 MessageBox::Show("Warning, NO Mark!!");
				 ErrorMessage("Warning, NO Mark!!");
				 return;
			 }
			 C2 = C_Center;

			 RelMotion(0, -5, GSpeed);
			 StartMove(0);

			 if(InPosition(0) != 1 || InPosition(1) != 1)
			 {
				 MessageBox::Show("馬達定位等候逾時!!");
				 ErrorMessage("馬達定位等候逾時!!");
				 return;
			 }

			 Sleep(500);
			 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

			 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, 300) == 0)
			 {
				 MessageBox::Show("Warning, NO Mark!!");
				 ErrorMessage("Warning, NO Mark!!");
				 return;
			 }
			 C3 = C_Center;

			 pixelSize = 9 / ( Distance(C1, C3) + Distance(C1, C2));
			 SaveSetting();

			 lX_Pos->Text = Distance(C2, C3).ToString();
			 lY_Pos->Text = Distance(C1, C2).ToString();
		 }
private: System::Void bGetCameraOriginal_Click(System::Object^  sender, System::EventArgs^  e) {
			 double pos;
			 pos = GetPosition(0);
			 tORIGINAL_X->Text = pos.ToString();
			 G_mOx = pos;

			  pos = GetPosition(1);
			 tORIGINAL_Y->Text = pos.ToString();
			 G_mOy = pos;

			 SaveSetting();


		 }
private: System::Void bCameraCalibration_Click(System::Object^  sender, System::EventArgs^  e) {
			 _25HolesCalibration();
		 }
private: System::Void bLaserCalibration_Click(System::Object^  sender, System::EventArgs^  e) {
			 cv::Point2f CCD, Laser;
			 double pos;
			 //GT_GetAtlPos(1, &pos);
			 CCD.x = GetPosition(0);
			 //GT_GetAtlPos(2, &pos);
			 CCD.y = GetPosition(1);

			 RelMotion(0, dis_CCD2Laser_X, GSpeed);
			 RelMotion(1, dis_CCD2Laser_Y, GSpeed);
			 StartMove(-1);

			 if(InPosition(0) != 1 || InPosition(1) != 1)
			 {
				 MessageBox::Show("馬達定位等候逾時!!");
				 ErrorMessage("馬達定位等候逾時!!");
				 return;
			 }

			 int temp = m_samlight->ScMarkEntityByName("test", 1);

			 RelMotion(0, -dis_CCD2Laser_X, GSpeed);
			 RelMotion(1, -dis_CCD2Laser_Y, GSpeed);
			 StartMove(-1);

			 Sleep(2000);

			 if(InPosition(0) != 1 || InPosition(1) != 1)
			 {
				 MessageBox::Show("馬達定位等候逾時!!");
				 ErrorMessage("馬達定位等候逾時!!");
				 return;
			 }


			 cv::Point2f C_Center(320,240);
			 float C_Radius;
			 float dx, dy;
			 int count = 0;
			 //I32 ENCODEX;
			 

			 dx = 10;
			 dy = 10;

				 

			 while(( dx > 3 || dy > 3 ) && count < 10)
			 {

				 RelMotion(0, (C_Center.x-320)*pixelSize, GSpeed);
				 RelMotion(1, (C_Center.y-240)*pixelSize*(-1), GSpeed);
				 StartMove(-1);
				 Sleep(500);

				 if(InPosition(0) != 1 || InPosition(1) != 1)
				 {
					 MessageBox::Show("馬達定位等候逾時!!");
					 ErrorMessage("馬達定位等候逾時!!");
					 return;
				 }

				 AngeloRTV_Save_File(CCDPortNo, "CameraImage.bmp", 1, 0);

				 if( getCircle(&C_Center, &C_Radius, "CameraImage.bmp", G_thresh, 300) == 0)
				 {
					 MessageBox::Show("Warning, NO Mark!!");
					 ErrorMessage("Warning, NO Mark!");
					 return;
				 }

				 dx = C_Center.x - 320;
				 dy = C_Center.y - 240;

				 if(dx < 0)
					 dx = dx * (-1);
				 if(dy < 0)
					 dy = dy * (-1);
				 count ++;

			 }

			 if( count == 10)
			 {
				 MessageBox::Show("Warning, fiduical mark fail!!");
				 ErrorMessage("Warning, fiduical mark fail!!");
				 return;
			 }

			 
			 Laser.x = GetPosition(0);
			 dis_CCD2Laser_X = dis_CCD2Laser_X - (Laser.x-CCD.x)+(C_Center.x-320) * pixelSize;
			 lX_Pos->Text = dis_CCD2Laser_X.ToString();

			 Laser.y = GetPosition(1);
			 dis_CCD2Laser_Y = dis_CCD2Laser_Y - (Laser.y-CCD.y)-(C_Center.y-240) * pixelSize;
			 lY_Pos->Text = dis_CCD2Laser_Y.ToString();

			 SaveSetting();
		 }
private: System::Void bGetPos_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(timer_GetPos->Enabled == true)
				 timer_GetPos->Enabled = false;
			 else
				 timer_GetPos->Enabled = true;

		 }
private: System::Void timer_GetPos_Tick(System::Object^  sender, System::EventArgs^  e) {
			 double ENCODEX;
			 ENCODEX = GetPosition(0);
			 lX_Pos->Text=(ENCODEX).ToString();
			 ENCODEX = GetPosition(0);			 
			 lY_Pos->Text=(ENCODEX).ToString();
		 }
private: System::Void bShowLine_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(showLine == 0)
				 showLine = 1;
			 else
				 showLine = 0;
		 }
private: System::Void bGoHome_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

