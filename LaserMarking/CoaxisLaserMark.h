#pragma once
 
#include "cv.h"  
#include "cxcore.h"  
#include "highgui.h"
#include "opencv2/opencv.hpp"
#include "Angelo.h"
#include "AngeloRTVErrorCode.h"
#include "Type_def.h"
#include "Marking.h"
#include "OpenCV.h"
#include "MarkPoint.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#define MAX_CORNERS 1000
#define IMGSRC_NAME "camera_current.bmp"




namespace LaserMarking {

	/// <summary>
	/// Summary for CoaxisLaserMark
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CoaxisLaserMark : public System::Windows::Forms::Form
	{
	public:
		CoaxisLaserMark(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CoaxisLaserMark()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pic_current;
	private:
		//影像范围
		int g_pic_height ;
		int g_pic_width ;
		// 基准参数
		double m_center_x;//基准中心点
		double m_center_y;
		double m_angle;//基准角度

		// 电脑摄像头
		CvCapture* m_capture;
		
	protected: 
























	private: System::Windows::Forms::PictureBox^  pb_total_pic;


	private: System::Windows::Forms::Button^  btn_calc_offset;
	private: System::Windows::Forms::Button^  btn_start_mark;
	private: System::Windows::Forms::GroupBox^  groupBox4;


	private: System::Windows::Forms::TextBox^  tb_job_width;




	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  tb_mark_height;
	private: System::Windows::Forms::TextBox^  tb_mark_width;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  tmr_capture;
	private: System::Windows::Forms::Button^  btn_corner_check;


	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  tb_entity_name;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tb_job_height;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  tb_model_height;
	private: System::Windows::Forms::TextBox^  tb_model_width;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  btn_ratio_y;

	private: System::Windows::Forms::Button^  btn_ratio_x;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  tb_ratio_x;
	private: System::Windows::Forms::TextBox^  tb_ratio_y;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
private: AxSAMLIGHT_CLIENT_CTRL_OCXLib::AxScSamlightClientCtrl^  m_samlight;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::TextBox^  tb_standard_center_y;

private: System::Windows::Forms::TextBox^  tb_standard_center_x;

private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TextBox^  tb_standard_angle;
private: System::Windows::Forms::Button^  btn_stander_set;
private: System::Windows::Forms::TabPage^  tabPage3;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::RadioButton^  rb_cap;

private: System::Windows::Forms::RadioButton^  rb_rtv;
private: System::Windows::Forms::ComboBox^  cb_capture_select;

private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Button^  btn_cap;
private: System::Windows::Forms::CheckBox^  cb_y;
private: System::Windows::Forms::CheckBox^  cb_x;
private: System::Windows::Forms::CheckBox^  cb_xy;


	private: System::ComponentModel::IContainer^  components;












	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CoaxisLaserMark::typeid));
			this->pic_current = (gcnew System::Windows::Forms::PictureBox());
			this->pb_total_pic = (gcnew System::Windows::Forms::PictureBox());
			this->btn_calc_offset = (gcnew System::Windows::Forms::Button());
			this->btn_start_mark = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_job_height = (gcnew System::Windows::Forms::TextBox());
			this->tb_job_width = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_mark_height = (gcnew System::Windows::Forms::TextBox());
			this->tb_mark_width = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tmr_capture = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_corner_check = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_entity_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_stander_set = (gcnew System::Windows::Forms::Button());
			this->tb_standard_angle = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tb_standard_center_y = (gcnew System::Windows::Forms::TextBox());
			this->tb_standard_center_x = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btn_ratio_y = (gcnew System::Windows::Forms::Button());
			this->btn_ratio_x = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_ratio_x = (gcnew System::Windows::Forms::TextBox());
			this->tb_ratio_y = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_model_height = (gcnew System::Windows::Forms::TextBox());
			this->tb_model_width = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->cb_y = (gcnew System::Windows::Forms::CheckBox());
			this->cb_x = (gcnew System::Windows::Forms::CheckBox());
			this->cb_xy = (gcnew System::Windows::Forms::CheckBox());
			this->btn_cap = (gcnew System::Windows::Forms::Button());
			this->cb_capture_select = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->rb_cap = (gcnew System::Windows::Forms::RadioButton());
			this->rb_rtv = (gcnew System::Windows::Forms::RadioButton());
			this->m_samlight = (gcnew AxSAMLIGHT_CLIENT_CTRL_OCXLib::AxScSamlightClientCtrl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic_current))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pb_total_pic))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_samlight))->BeginInit();
			this->SuspendLayout();
			// 
			// pic_current
			// 
			this->pic_current->Location = System::Drawing::Point(0, 1);
			this->pic_current->Name = L"pic_current";
			this->pic_current->Size = System::Drawing::Size(351, 261);
			this->pic_current->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pic_current->TabIndex = 1;
			this->pic_current->TabStop = false;
			// 
			// pb_total_pic
			// 
			this->pb_total_pic->Location = System::Drawing::Point(0, 268);
			this->pb_total_pic->Name = L"pb_total_pic";
			this->pb_total_pic->Size = System::Drawing::Size(351, 346);
			this->pb_total_pic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_total_pic->TabIndex = 9;
			this->pb_total_pic->TabStop = false;
			// 
			// btn_calc_offset
			// 
			this->btn_calc_offset->BackColor = System::Drawing::Color::MediumAquamarine;
			this->btn_calc_offset->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_calc_offset->Location = System::Drawing::Point(545, 311);
			this->btn_calc_offset->Name = L"btn_calc_offset";
			this->btn_calc_offset->Size = System::Drawing::Size(149, 96);
			this->btn_calc_offset->TabIndex = 10;
			this->btn_calc_offset->Text = L"启动视觉定位";
			this->btn_calc_offset->UseVisualStyleBackColor = false;
			this->btn_calc_offset->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::btn_calc_offset_Click);
			// 
			// btn_start_mark
			// 
			this->btn_start_mark->BackColor = System::Drawing::Color::LightPink;
			this->btn_start_mark->Location = System::Drawing::Point(378, 446);
			this->btn_start_mark->Name = L"btn_start_mark";
			this->btn_start_mark->Size = System::Drawing::Size(149, 96);
			this->btn_start_mark->TabIndex = 11;
			this->btn_start_mark->Text = L"开始打标";
			this->btn_start_mark->UseVisualStyleBackColor = false;
			this->btn_start_mark->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::btn_start_mark_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tb_job_height);
			this->groupBox4->Controls->Add(this->tb_job_width);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Location = System::Drawing::Point(212, 15);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(200, 55);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"工件尺寸(单位：mm)";
			// 
			// tb_job_height
			// 
			this->tb_job_height->Location = System::Drawing::Point(49, 20);
			this->tb_job_height->Name = L"tb_job_height";
			this->tb_job_height->Size = System::Drawing::Size(53, 21);
			this->tb_job_height->TabIndex = 6;
			this->tb_job_height->Text = L"43.5";
			// 
			// tb_job_width
			// 
			this->tb_job_width->Location = System::Drawing::Point(141, 20);
			this->tb_job_width->Name = L"tb_job_width";
			this->tb_job_width->Size = System::Drawing::Size(53, 21);
			this->tb_job_width->TabIndex = 5;
			this->tb_job_width->Text = L"40";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(20, 23);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 12);
			this->label7->TabIndex = 2;
			this->label7->Text = L"高：";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(112, 23);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 12);
			this->label8->TabIndex = 3;
			this->label8->Text = L"宽：";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tb_mark_height);
			this->groupBox1->Controls->Add(this->tb_mark_width);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(6, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 55);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"标记尺寸(单位：mm)";
			// 
			// tb_mark_height
			// 
			this->tb_mark_height->Location = System::Drawing::Point(49, 20);
			this->tb_mark_height->Name = L"tb_mark_height";
			this->tb_mark_height->Size = System::Drawing::Size(53, 21);
			this->tb_mark_height->TabIndex = 4;
			this->tb_mark_height->Text = L"480";
			// 
			// tb_mark_width
			// 
			this->tb_mark_width->Location = System::Drawing::Point(141, 20);
			this->tb_mark_width->Name = L"tb_mark_width";
			this->tb_mark_width->Size = System::Drawing::Size(53, 21);
			this->tb_mark_width->TabIndex = 5;
			this->tb_mark_width->Text = L"640";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"高：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(112, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"宽：";
			// 
			// tmr_capture
			// 
			this->tmr_capture->Tick += gcnew System::EventHandler(this, &CoaxisLaserMark::tmr_capture_Tick);
			// 
			// btn_corner_check
			// 
			this->btn_corner_check->BackColor = System::Drawing::Color::LightPink;
			this->btn_corner_check->Location = System::Drawing::Point(378, 311);
			this->btn_corner_check->Name = L"btn_corner_check";
			this->btn_corner_check->Size = System::Drawing::Size(149, 96);
			this->btn_corner_check->TabIndex = 12;
			this->btn_corner_check->Text = L"检点检测";
			this->btn_corner_check->UseVisualStyleBackColor = false;
			this->btn_corner_check->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::btn_corner_check_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tb_entity_name);
			this->groupBox5->Controls->Add(this->label3);
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Controls->Add(this->textBox1);
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->checkBox1);
			this->groupBox5->Location = System::Drawing::Point(6, 87);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(200, 121);
			this->groupBox5->TabIndex = 13;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"打标设置";
			this->groupBox5->Enter += gcnew System::EventHandler(this, &CoaxisLaserMark::groupBox5_Enter);
			// 
			// tb_entity_name
			// 
			this->tb_entity_name->Location = System::Drawing::Point(87, 26);
			this->tb_entity_name->Name = L"tb_entity_name";
			this->tb_entity_name->Size = System::Drawing::Size(84, 21);
			this->tb_entity_name->TabIndex = 8;
			this->tb_entity_name->Text = L"sunlike";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 7;
			this->label3->Text = L"实体名称：";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(177, 60);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 12);
			this->label5->TabIndex = 6;
			this->label5->Text = L"ms";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(87, 57);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(84, 21);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 60);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 12);
			this->label4->TabIndex = 5;
			this->label4->Text = L"打标时间：";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(21, 85);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(96, 16);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"开启自动打标";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(429, 1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(438, 293);
			this->tabControl1->TabIndex = 14;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox6);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Location = System::Drawing::Point(4, 21);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(430, 268);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"打标设置";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->btn_stander_set);
			this->groupBox6->Controls->Add(this->tb_standard_angle);
			this->groupBox6->Controls->Add(this->label13);
			this->groupBox6->Controls->Add(this->tb_standard_center_y);
			this->groupBox6->Controls->Add(this->tb_standard_center_x);
			this->groupBox6->Controls->Add(this->label12);
			this->groupBox6->Location = System::Drawing::Point(222, 87);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(190, 121);
			this->groupBox6->TabIndex = 14;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"基准矫正";
			// 
			// btn_stander_set
			// 
			this->btn_stander_set->BackColor = System::Drawing::Color::LimeGreen;
			this->btn_stander_set->Location = System::Drawing::Point(17, 92);
			this->btn_stander_set->Name = L"btn_stander_set";
			this->btn_stander_set->Size = System::Drawing::Size(75, 23);
			this->btn_stander_set->TabIndex = 13;
			this->btn_stander_set->Text = L"设置矫正";
			this->btn_stander_set->UseVisualStyleBackColor = false;
			this->btn_stander_set->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::btn_stander_set_Click);
			// 
			// tb_standard_angle
			// 
			this->tb_standard_angle->Location = System::Drawing::Point(89, 59);
			this->tb_standard_angle->Name = L"tb_standard_angle";
			this->tb_standard_angle->Size = System::Drawing::Size(42, 21);
			this->tb_standard_angle->TabIndex = 12;
			this->tb_standard_angle->Text = L"0";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 66);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(77, 12);
			this->label13->TabIndex = 11;
			this->label13->Text = L"  参考角度：";
			// 
			// tb_standard_center_y
			// 
			this->tb_standard_center_y->Location = System::Drawing::Point(142, 32);
			this->tb_standard_center_y->Name = L"tb_standard_center_y";
			this->tb_standard_center_y->Size = System::Drawing::Size(42, 21);
			this->tb_standard_center_y->TabIndex = 10;
			this->tb_standard_center_y->Text = L"0";
			// 
			// tb_standard_center_x
			// 
			this->tb_standard_center_x->Location = System::Drawing::Point(89, 32);
			this->tb_standard_center_x->Name = L"tb_standard_center_x";
			this->tb_standard_center_x->Size = System::Drawing::Size(42, 21);
			this->tb_standard_center_x->TabIndex = 9;
			this->tb_standard_center_x->Text = L"0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 35);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(77, 12);
			this->label12->TabIndex = 8;
			this->label12->Text = L"参考中心点：";
			this->label12->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::label12_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->btn_ratio_y);
			this->tabPage2->Controls->Add(this->btn_ratio_x);
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 21);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(430, 268);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"影像倍率";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// btn_ratio_y
			// 
			this->btn_ratio_y->BackColor = System::Drawing::Color::MediumAquamarine;
			this->btn_ratio_y->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_ratio_y->Location = System::Drawing::Point(182, 184);
			this->btn_ratio_y->Name = L"btn_ratio_y";
			this->btn_ratio_y->Size = System::Drawing::Size(149, 45);
			this->btn_ratio_y->TabIndex = 12;
			this->btn_ratio_y->Text = L"计算倍率Y";
			this->btn_ratio_y->UseVisualStyleBackColor = false;
			this->btn_ratio_y->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::btn_ratio_y_Click);
			// 
			// btn_ratio_x
			// 
			this->btn_ratio_x->BackColor = System::Drawing::Color::MediumAquamarine;
			this->btn_ratio_x->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_ratio_x->Location = System::Drawing::Point(16, 184);
			this->btn_ratio_x->Name = L"btn_ratio_x";
			this->btn_ratio_x->Size = System::Drawing::Size(149, 45);
			this->btn_ratio_x->TabIndex = 11;
			this->btn_ratio_x->Text = L"计算倍率X";
			this->btn_ratio_x->UseVisualStyleBackColor = false;
			this->btn_ratio_x->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::btn_ratio_x_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tb_ratio_x);
			this->groupBox3->Controls->Add(this->tb_ratio_y);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Location = System::Drawing::Point(16, 84);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 55);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"倍率(px/mm)";
			// 
			// tb_ratio_x
			// 
			this->tb_ratio_x->Location = System::Drawing::Point(49, 20);
			this->tb_ratio_x->Name = L"tb_ratio_x";
			this->tb_ratio_x->Size = System::Drawing::Size(53, 21);
			this->tb_ratio_x->TabIndex = 6;
			this->tb_ratio_x->Text = L"9.348";
			// 
			// tb_ratio_y
			// 
			this->tb_ratio_y->Location = System::Drawing::Point(141, 20);
			this->tb_ratio_y->Name = L"tb_ratio_y";
			this->tb_ratio_y->Size = System::Drawing::Size(53, 21);
			this->tb_ratio_y->TabIndex = 5;
			this->tb_ratio_y->Text = L"8.493";
			this->tb_ratio_y->TextChanged += gcnew System::EventHandler(this, &CoaxisLaserMark::textBox5_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(20, 23);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(23, 12);
			this->label10->TabIndex = 2;
			this->label10->Text = L"X：";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(112, 23);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(23, 12);
			this->label11->TabIndex = 3;
			this->label11->Text = L"Y：";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tb_model_height);
			this->groupBox2->Controls->Add(this->tb_model_width);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Location = System::Drawing::Point(16, 23);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 55);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"模型尺寸(单位：mm)";
			// 
			// tb_model_height
			// 
			this->tb_model_height->Location = System::Drawing::Point(49, 20);
			this->tb_model_height->Name = L"tb_model_height";
			this->tb_model_height->Size = System::Drawing::Size(53, 21);
			this->tb_model_height->TabIndex = 6;
			this->tb_model_height->Text = L"21.9";
			// 
			// tb_model_width
			// 
			this->tb_model_width->Location = System::Drawing::Point(141, 20);
			this->tb_model_width->Name = L"tb_model_width";
			this->tb_model_width->Size = System::Drawing::Size(53, 21);
			this->tb_model_width->TabIndex = 5;
			this->tb_model_width->Text = L"21.5";
			this->tb_model_width->TextChanged += gcnew System::EventHandler(this, &CoaxisLaserMark::textBox3_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 23);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 12);
			this->label6->TabIndex = 2;
			this->label6->Text = L"高：";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(112, 23);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(29, 12);
			this->label9->TabIndex = 3;
			this->label9->Text = L"宽：";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox7);
			this->tabPage3->Location = System::Drawing::Point(4, 21);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(430, 268);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"摄像头设置";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->cb_y);
			this->groupBox7->Controls->Add(this->cb_x);
			this->groupBox7->Controls->Add(this->cb_xy);
			this->groupBox7->Controls->Add(this->btn_cap);
			this->groupBox7->Controls->Add(this->cb_capture_select);
			this->groupBox7->Controls->Add(this->label14);
			this->groupBox7->Controls->Add(this->rb_cap);
			this->groupBox7->Controls->Add(this->rb_rtv);
			this->groupBox7->Location = System::Drawing::Point(17, 17);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(388, 223);
			this->groupBox7->TabIndex = 0;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"摄像头设置";
			// 
			// cb_y
			// 
			this->cb_y->AutoSize = true;
			this->cb_y->Location = System::Drawing::Point(57, 162);
			this->cb_y->Name = L"cb_y";
			this->cb_y->Size = System::Drawing::Size(54, 16);
			this->cb_y->TabIndex = 7;
			this->cb_y->Text = L"Y反向";
			this->cb_y->UseVisualStyleBackColor = true;
			// 
			// cb_x
			// 
			this->cb_x->AutoSize = true;
			this->cb_x->Location = System::Drawing::Point(57, 140);
			this->cb_x->Name = L"cb_x";
			this->cb_x->Size = System::Drawing::Size(54, 16);
			this->cb_x->TabIndex = 6;
			this->cb_x->Text = L"X反向";
			this->cb_x->UseVisualStyleBackColor = true;
			// 
			// cb_xy
			// 
			this->cb_xy->AutoSize = true;
			this->cb_xy->Location = System::Drawing::Point(57, 118);
			this->cb_xy->Name = L"cb_xy";
			this->cb_xy->Size = System::Drawing::Size(60, 16);
			this->cb_xy->TabIndex = 5;
			this->cb_xy->Text = L"XY反向";
			this->cb_xy->UseVisualStyleBackColor = true;
			// 
			// btn_cap
			// 
			this->btn_cap->Location = System::Drawing::Point(42, 194);
			this->btn_cap->Name = L"btn_cap";
			this->btn_cap->Size = System::Drawing::Size(75, 23);
			this->btn_cap->TabIndex = 4;
			this->btn_cap->Text = L"暂停";
			this->btn_cap->UseVisualStyleBackColor = true;
			this->btn_cap->Click += gcnew System::EventHandler(this, &CoaxisLaserMark::button1_Click);
			// 
			// cb_capture_select
			// 
			this->cb_capture_select->FormattingEnabled = true;
			this->cb_capture_select->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", 
				L"7", L"8", L"9", L"10"});
			this->cb_capture_select->Location = System::Drawing::Point(138, 84);
			this->cb_capture_select->Name = L"cb_capture_select";
			this->cb_capture_select->Size = System::Drawing::Size(121, 20);
			this->cb_capture_select->TabIndex = 3;
			this->cb_capture_select->Text = L"0";
			this->cb_capture_select->SelectedIndexChanged += gcnew System::EventHandler(this, &CoaxisLaserMark::comboBox1_SelectedIndexChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(55, 87);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(77, 12);
			this->label14->TabIndex = 2;
			this->label14->Text = L"摄像头选择：";
			// 
			// rb_cap
			// 
			this->rb_cap->AutoSize = true;
			this->rb_cap->Location = System::Drawing::Point(34, 59);
			this->rb_cap->Name = L"rb_cap";
			this->rb_cap->Size = System::Drawing::Size(83, 16);
			this->rb_cap->TabIndex = 1;
			this->rb_cap->Text = L"普通摄像头";
			this->rb_cap->UseVisualStyleBackColor = true;
			this->rb_cap->CheckedChanged += gcnew System::EventHandler(this, &CoaxisLaserMark::radioButton1_CheckedChanged);
			// 
			// rb_rtv
			// 
			this->rb_rtv->AutoSize = true;
			this->rb_rtv->Checked = true;
			this->rb_rtv->Location = System::Drawing::Point(34, 37);
			this->rb_rtv->Name = L"rb_rtv";
			this->rb_rtv->Size = System::Drawing::Size(113, 16);
			this->rb_rtv->TabIndex = 0;
			this->rb_rtv->TabStop = true;
			this->rb_rtv->Text = L"RTV-2视频采集卡";
			this->rb_rtv->UseVisualStyleBackColor = true;
			// 
			// m_samlight
			// 
			this->m_samlight->Enabled = true;
			this->m_samlight->Location = System::Drawing::Point(378, 548);
			this->m_samlight->Name = L"m_samlight";
			this->m_samlight->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^  >(resources->GetObject(L"m_samlight.OcxState")));
			this->m_samlight->Size = System::Drawing::Size(100, 50);
			this->m_samlight->TabIndex = 85;
			this->m_samlight->Visible = false;
			// 
			// CoaxisLaserMark
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 637);
			this->Controls->Add(this->m_samlight);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btn_corner_check);
			this->Controls->Add(this->btn_start_mark);
			this->Controls->Add(this->btn_calc_offset);
			this->Controls->Add(this->pb_total_pic);
			this->Controls->Add(this->pic_current);
			this->Name = L"CoaxisLaserMark";
			this->Text = L"CoaxisLaserMark";
			this->Load += gcnew System::EventHandler(this, &CoaxisLaserMark::CoaxisLaserMark_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic_current))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pb_total_pic))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->m_samlight))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
		
			private: System::Void btn_start_mark_Click(System::Object^  sender, System::EventArgs^  e) 
			{

			}

			CvPoint getNextMinLoc(IplImage *result, CvPoint minLoc, int maxVaule, int templatW, int templatH)  
			{  

						 // 先将第一个最小值点附近两倍模板宽度和高度的都设置为最大值防止产生干扰  
						 int startX = minLoc.x - templatW;  
						 int startY = minLoc.y - templatH;  
						 int endX = minLoc.x + templatW;  
						 int endY = minLoc.y + templatH;  
						 if(startX < 0 || startY < 0)  
						 {  
							 startX = 0;  
							 startY = 0;  
						 }  
						 if(endX > result->width - 1 || endY > result->height - 1)  
						 {  
							 endX = result->width - 1;  
							 endY = result->height - 1;  
						 }  
						 int y, x;  
						 for(y = startY; y < endY; y++)  
						 {  
							 for(x = startX; x < endX; x++)  
							 {  
								 cvSetReal2D(result, y, x, maxVaule);  
							 }  
						 }
					
					 // 然后得到下一个最小值并且返回  
					 double new_minVaule, new_maxValue;  
					 CvPoint new_minLoc, new_maxLoc;  
					 cvMinMaxLoc(result, &new_minVaule, &new_maxValue, &new_minLoc, &new_maxLoc);  
					 return new_minLoc;  

			}  

 
			CMarkPoint  GetLocation(const char* fileName)
			{
				cv::Mat imgSrc = cv::imread(IMGSRC_NAME);
				cv::Mat imgTmpl = cv::imread(fileName);
				blur(imgSrc, imgSrc, cv::Size(4, 4));
				blur(imgTmpl, imgTmpl, cv::Size(4, 4));
				cv::threshold(imgSrc, imgSrc, 128, 255, 0);
				cv::threshold(imgTmpl, imgTmpl, 128, 255, 0);
				cv::Mat imgRes,imgMask;
				cv::Point        minloc, maxloc;   
				double        minval, maxval; 
				int            img_width, img_height;   
				int            tpl_width, tpl_height;   
				int            res_width, res_height; 

				img_width  = imgSrc.cols;   
				img_height = imgSrc.rows;   
				tpl_width  = imgTmpl.cols;   
				tpl_height = imgTmpl.rows;   
				res_width  = img_width - tpl_width + 1;   
				res_height = img_height - tpl_height + 1;   

				/* create new image for template matching computation */   
				imgRes = cvCreateImage( cvSize( res_width, res_height ), IPL_DEPTH_32F, 1 );   

				/* choose template matching method to be used */   
				matchTemplate( imgSrc, imgTmpl, imgRes, CV_TM_SQDIFF ); 

				//for (int i = 0; i < 8;++i)
				{
					cv::minMaxLoc( imgRes, &minval, &maxval, &minloc, &maxloc,imgMask);   

					/* draw white rectangle */   
					rectangle( imgSrc,cvPoint( minloc.x, minloc.y ),cvPoint( minloc.x + tpl_width, minloc.y + tpl_height ),   
						cvScalar( 0, 0, 255, 0 ), 1, 0, 0 ); 

				}

			 
				  

				string name1 = "imgSrc";
				name1+=fileName;
				imshow( name1, imgSrc );  
				return CMarkPoint(minloc,cvSize(tpl_width,tpl_height));   

			}

		


			void GetLocation( )
			{
				 CMarkPoint markPoint1 = GetLocation("template1.bmp");
				 CMarkPoint markPoint2 = GetLocation("template.bmp");

				 cv::Point2d center1 = markPoint1.GetMarkPoint();
				 cv::Point2d center2 = markPoint2.GetMarkPoint(); 
				 cv::Point2d center = cvPoint((center1.x+center2.x)/2.0,(center1.y+center2.y)/2.0);


			 
				 double angle = CMarkPoint::GetAngle(markPoint1.GetMarkPoint(0,0),markPoint2.GetMarkPoint(0,0));
				 /*
				 double height =0,width = 0;
				 double::TryParse(tb_job_height->Text, height);
				 double::TryParse(tb_job_width->Text, width); 

				 double standAngle =atan(height/width)*180/PI;
				 */

				 double rotate = m_angle - angle; 
				 
				 double ratioX = 1.0;
				 double ratioY = 1.0;
				 double::TryParse(tb_ratio_x->Text,ratioX);
				 double::TryParse(tb_ratio_y->Text,ratioY);

				 System::String^ strName = this->tb_entity_name->Text;
				 double x = 0.0;
				 double y = 0.0;
				 calcOffset(x,y,center);

				 char deugStr[129]={0};
				 sprintf(deugStr,"Center[%f,%f],angle:%f rotate:%f",x,y,angle,rotate);;
				 OutputDebugStringA(deugStr);
					
				
				 SetTransform(strName,x,y,rotate,ratioX,ratioY);

				 LaserMarkStart(strName);
				 

				 ResetTransform(strName,0-rotate);


			}

			void LaserMarkStart(System::String^ entityName)
			{
				m_samlight->ScMarkEntityByName(entityName,1);
				while (m_samlight->ScIsMarking())
				{
					Sleep(10);
				}
			}


			void calcOffset(double & x,double& y,cv::Point currentCenter)
			{
				x = currentCenter.x - m_center_x;
				y = m_center_y - currentCenter.y;
			}

			void SetTransform(System::String^ entityName,const double &offsetX, const double &offsetY,const double &angle, const double & ratioX,const double &ratioY)
			{

				double x =  offsetX / ratioX;
				double y = offsetY / ratioY;
			    
				m_samlight->ScSwitchLaser(1);			   
				m_samlight->ScRotateEntity(entityName,0,0,angle);  
				m_samlight->ScTranslateEntity(entityName,x,y,0.0); 
 
			}

			void ResetTransform(System::String^ entityName,const double & angle)
			{
				double min_x = 0.0,min_y =0.0,max_x = 0.0,max_y =0.0;
				min_x = m_samlight->ScGetEntityOutline(entityName,0);
				min_y = m_samlight->ScGetEntityOutline(entityName,1);
				max_x = m_samlight->ScGetEntityOutline(entityName,3);
				max_y = m_samlight->ScGetEntityOutline(entityName,4);
				double center_x = 0.0,center_y = 0.0;
				center_x = (min_x+max_x)/2.0;
				center_y = (min_y+max_y)/2.0;
				m_samlight->ScOpticMatrixReset();

			    m_samlight->ScTranslateEntity(entityName,0 - center_x,0 - center_y,0.0); 
				m_samlight->ScRotateEntity(entityName,0,0,angle); 

			}



			 


            private: System::Void btn_calc_offset_Click(System::Object^  sender, System::EventArgs^  e) 
		    {
				 
				int::TryParse(tb_mark_height->Text,g_pic_height);
				int::TryParse(tb_mark_width->Text,g_pic_width);
 				 GetLocation();
			 

		    }



			IplImage* DoPyrDown(IplImage*image,int height,int width)
			{
				CvSize size = cvSize(width,height);
				IplImage* outImage = cvCreateImage(size,image->depth,image->nChannels);
				cvPyrDown(image,outImage);
				cvReleaseImage(&image);
				return outImage;
			}


			void save(const char* fileName)
			{

				if(this->m_capture==NULL)
				{
					return ;

				}

				try
				{
				
					
			
			 
				IplImage* frame = cvQueryFrame(this->m_capture);
				// initialize a pic 
				IplImage* outImage = cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
				 
				cvConvertImage(frame,outImage,1);

			   
				
				//zoom 
				//outImage = DoPyrDown(outImage,g_pic_width,g_pic_height);

				cv::Mat imgsrc(outImage),imgOut(outImage);
				
				//cv::threshold(imgOut, imgOut, 128, 255, 0);

				if(this->cb_x->Checked || this->cb_xy->Checked || cb_y->Checked)
				{

					//transpose(imgsrc,imgOut);
					if(this->cb_xy->Checked)
					{						
						//flip(imgOut,imgOut,-1); 
					}

					if(this->cb_x->Checked)
					{						
						//flip(imgOut,imgOut,0); 
					}

					if(this->cb_y->Checked)
					{						
						//flip(imgOut,imgOut,1); 
					}
				}
				
				 

				cv::imwrite(fileName,imgsrc);
				}
				catch (...)
				{
				}

			}
			




           private: System::Void tmr_capture_Tick(System::Object^  sender, System::EventArgs^  e) 
					{
						if(this->rb_rtv->Checked)
						{
							I16 result;
							result = AngeloRTV_Save_File(CCDPortNo, IMGSRC_NAME, 1, 0);
						}
						else if(this->rb_cap->Checked)
						{
							save(IMGSRC_NAME);

						}
			 cv::Mat ImgCurrent = cv::imread(IMGSRC_NAME, 1);

			 // 显示中间基准线
			 cv::Scalar color(0, 0, 255);
			 int img_width  = ImgCurrent.cols;   
			 int img_height = ImgCurrent.rows;  
			 cv::line(ImgCurrent, cv::Point(img_width/2, 0), cv::Point(img_width/2, img_height), color, 2, 8, 0);
			 cv::line(ImgCurrent, cv::Point(0, img_height/2), cv::Point(img_width, img_height/2), color, 2, 8, 0);
try
{
	System::Drawing::Graphics^ graphics = pic_current->CreateGraphics();
	System::IntPtr ptr(ImgCurrent.ptr());
	System::Drawing::Bitmap^ b  = gcnew System::Drawing::Bitmap(ImgCurrent.cols,ImgCurrent.rows,ImgCurrent.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr);
	System::Drawing::RectangleF rect(0,0,pic_current->Width,pic_current->Height);
	graphics->DrawImage(b,rect);

}
catch (...)
{
	
}


		
		 }

					// 默认加载设置
private: System::Void CoaxisLaserMark_Load(System::Object^  sender, System::EventArgs^  e) {
			  I16 result = AngeloRTV_Initial(CCDPortNo);
			 result = AngeloRTV_Software_Reset(CCDPortNo);
			 result = AngeloRTV_Set_Color_Format(CCDPortNo, 1); //GRAY
			 result = AngeloRTV_Set_Video_Format(CCDPortNo, 0); //FULLNTSC
			 result = AngeloRTV_Capture_Start(CCDPortNo, 0xFFFFFFFF); 


			 int::TryParse(tb_mark_height->Text,g_pic_height);
			 int::TryParse(tb_mark_width->Text, g_pic_width); 



			 this->rb_rtv->Checked = true;
			 //tmr_capture->Enabled =true;

			 m_capture = NULL;
		 }
private: System::Void btn_corner_check_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				 
				 
				//cv:Point corners[MAX_CORNERS]; // output point list
			    std::vector<cv::Point> corners;
				cv::Mat imgSrc,grayImgSrc,corners1,corners2;
			
				CvScalar color = CV_RGB(255,0,0);
				imgSrc = cv::imread(IMGSRC_NAME,1);
				int img_width  = imgSrc.cols;   
				int img_height = imgSrc.rows;  

				
				grayImgSrc = cvCreateImage(cvSize(img_width,img_height),IPL_DEPTH_8U,1);
				//copy the source image to copy image after converting the format
				cv::cvtColor(imgSrc,grayImgSrc,CV_BGR2GRAY);
				 
				// create empty imgage os same size as the copied images 
				corners1 = cvCreateImage(cvSize(img_width,img_height),IPL_DEPTH_32F,1);
				corners2 = cvCreateImage(cvSize(img_width,img_height),IPL_DEPTH_32F,1);

				cv::goodFeaturesToTrack(grayImgSrc,corners,MAX_CORNERS,
					0.1,20);
				
				for(std::vector<cv::Point>::iterator iter = corners.begin() ;iter != corners.end() ;++iter)
				{
					 
				    circle(imgSrc,*iter,3,color,1,CV_AA,0);
				}

				System::Drawing::Graphics^ graphics = pb_total_pic->CreateGraphics();
				System::IntPtr ptr(imgSrc.ptr());
				System::Drawing::Bitmap^ b  = gcnew System::Drawing::Bitmap(imgSrc.cols,imgSrc.rows,imgSrc.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr);
				System::Drawing::RectangleF rect(0,0,pb_total_pic->Width,pb_total_pic->Height);
				graphics->DrawImage(b,rect);

			
		 }


private: System::Void groupBox5_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }



		std::vector<cv::Point> GetCornerPointList()
		{
			std::vector<cv::Point> corners;
			cv::Mat imgSrc,grayImgSrc,corners1,corners2;

			CvScalar color = CV_RGB(255,0,0);
			imgSrc = cv::imread(IMGSRC_NAME,1);
			int img_width  = imgSrc.cols;   
			int img_height = imgSrc.rows;  
            g_pic_height = img_height;
			g_pic_width = img_width;

			grayImgSrc = cvCreateImage(cvSize(img_width,img_height),IPL_DEPTH_8U,1);
			//copy the source image to copy image after converting the format
			cv::cvtColor(imgSrc,grayImgSrc,CV_BGR2GRAY);

			// create empty imgage os same size as the copied images 
			corners1 = cvCreateImage(cvSize(img_width,img_height),IPL_DEPTH_32F,1);
			corners2 = cvCreateImage(cvSize(img_width,img_height),IPL_DEPTH_32F,1);

			cv::goodFeaturesToTrack(grayImgSrc,corners,MAX_CORNERS,
				0.1,20);

			for(std::vector<cv::Point>::iterator iter = corners.begin() ;iter != corners.end() ;++iter)
			{
				circle(imgSrc,*iter,3,color,1,CV_AA,0);
			}

			System::Drawing::Graphics^ graphics = pb_total_pic->CreateGraphics();
			System::IntPtr ptr(imgSrc.ptr());
			System::Drawing::Bitmap^ b  = gcnew System::Drawing::Bitmap(imgSrc.cols,imgSrc.rows,imgSrc.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr);
			System::Drawing::RectangleF rect(0,0,pb_total_pic->Width,pb_total_pic->Height);
			graphics->DrawImage(b,rect);
			ClockwiseSortPoints(corners);
			return corners;
		}



private: System::Void btn_ratio_x_Click(System::Object^  sender, System::EventArgs^  e) {

			 std::vector<cv::Point> corners = GetCornerPointList();
			 

			 if(corners.size() < 4)
			 {
				 MessageBox::Show("Corner count less than 4");
				 return ;
			 }
			 else if(corners.size() > 4)
			 {

				 MessageBox::Show("Corner count more than 4");
				return;
			 }

			 double width = 0;
			 Double::TryParse(this->tb_model_width->Text,width);
			 
			 double ratio = abs(corners[0].x - corners[2].x)/(1.0*width);
			 String ^strRatio = ""+ ratio;
			 
			 this->tb_ratio_x->Text = strRatio;

		 }
private: System::Void btn_ratio_y_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::vector<cv::Point> corners = GetCornerPointList();


			 if(corners.size() < 4)
			 {
				 MessageBox::Show("Corner count less than 4");
				 return ;
			 }
			 else if(corners.size() > 4)
			 {

				 MessageBox::Show("Corner count more than 4");
				 return;
			 }

			 double height = 0;
			 Double::TryParse(this->tb_model_height->Text,height);

			 double ratio = abs(corners[1].x - corners[3].x)/(1.0*height);
			 String ^strRatio = ""+ ratio;

			 this->tb_ratio_y->Text = strRatio;


		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
		 //设置矫正值
private: System::Void btn_stander_set_Click(System::Object^  sender, System::EventArgs^  e) {

			 CMarkPoint markPoint1 = GetLocation("template1.bmp");
			 CMarkPoint markPoint2 = GetLocation("template.bmp");
			
			 cv::Point2d center1 = markPoint1.GetMarkPoint();
			 cv::Point2d center2 = markPoint2.GetMarkPoint(); 
			 
			 cv::Point2d center= cvPoint((center1.x+center2.x)/2,(center1.y+center2.y)/2);

			 m_center_x = center.x;
			 m_center_y = center.y;

			 m_angle=CMarkPoint::GetAngle(markPoint1.GetMarkPoint(0,0),markPoint2.GetMarkPoint(0,0));

			 this->tb_standard_center_x->Text = ""+m_center_x;
			 this->tb_standard_center_y->Text = ""+m_center_y;
			 this->tb_standard_angle->Text = ""+m_angle;




		 }

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 int nSelect = this->cb_capture_select->SelectedIndex;
			 if(nSelect == -1)
			 {
				 nSelect = 0;
			 }
			 if(this->m_capture !=NULL)
			 {
				 //cvReleaseCapture(&m_capture);
				 this->m_capture = NULL;
				 
			 }

			 
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->cb_capture_select->Enabled = this->rb_cap->Checked;
		 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 tmr_capture->Enabled = !tmr_capture->Enabled;
 			 btn_cap->Text = tmr_capture->Enabled ? "暂停":"启动";
			 if(rb_cap->Checked)
			 {  

				 this->m_capture = cvCreateCameraCapture(1);
			 }
			 
		 }
};





}
