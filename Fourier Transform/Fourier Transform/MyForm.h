#pragma once
#include <iostream>
#include "DataManager.h"
#include "FT.h"
#define IMAGE_SIZE 256.f
namespace FourierTransform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			fourierTransformMethod = new FT();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadImageToolStripMenuItem;





	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;

	private: System::Windows::Forms::Label^  ResultImageLabel;
	private: System::Windows::Forms::PictureBox^  pictureBox_SourceImage;
	private: System::Windows::Forms::PictureBox^  pictureBox_OutputImage;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		/// <summary>
		DataManager * dataManager;
		FT*	fourierTransformMethod;
	private: System::Windows::Forms::PictureBox^  pictureBox_Inverse;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  highPassFilter;
	private: System::Windows::Forms::RadioButton^  LowPassFilter;
	private: System::Windows::Forms::HScrollBar^  radius;




	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;


			 /// </summary>
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
			 /// 這個方法的內容。
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->loadImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
				 this->pictureBox_SourceImage = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox_OutputImage = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox_Inverse = (gcnew System::Windows::Forms::PictureBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
				 this->highPassFilter = (gcnew System::Windows::Forms::RadioButton());
				 this->LowPassFilter = (gcnew System::Windows::Forms::RadioButton());
				 this->radius = (gcnew System::Windows::Forms::HScrollBar());
				 this->ResultImageLabel = (gcnew System::Windows::Forms::Label());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->tableLayoutPanel1->SuspendLayout();
				 this->menuStrip1->SuspendLayout();
				 this->flowLayoutPanel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_SourceImage))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_OutputImage))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Inverse))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->ColumnCount = 1;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 100)));
				 this->tableLayoutPanel1->Controls->Add(this->menuStrip1, 0, 0);
				 this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 0, 1);
				 this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 2;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.894737F)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 92.10526F)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(792, 317);
				 this->tableLayoutPanel1->TabIndex = 0;
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(792, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // fileToolStripMenuItem
				 // 
				 this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->loadImageToolStripMenuItem });
				 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				 this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
				 this->fileToolStripMenuItem->Text = L"File";
				 // 
				 // loadImageToolStripMenuItem
				 // 
				 this->loadImageToolStripMenuItem->Name = L"loadImageToolStripMenuItem";
				 this->loadImageToolStripMenuItem->Size = System::Drawing::Size(142, 22);
				 this->loadImageToolStripMenuItem->Text = L"Load Image";
				 this->loadImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadImageToolStripMenuItem_Click);
				 // 
				 // flowLayoutPanel1
				 // 
				 this->flowLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->flowLayoutPanel1->Controls->Add(this->pictureBox_SourceImage);
				 this->flowLayoutPanel1->Controls->Add(this->pictureBox_OutputImage);
				 this->flowLayoutPanel1->Controls->Add(this->pictureBox_Inverse);
				 this->flowLayoutPanel1->Controls->Add(this->label1);
				 this->flowLayoutPanel1->Controls->Add(this->checkBox2);
				 this->flowLayoutPanel1->Controls->Add(this->highPassFilter);
				 this->flowLayoutPanel1->Controls->Add(this->LowPassFilter);
				 this->flowLayoutPanel1->Controls->Add(this->radius);
				 this->flowLayoutPanel1->Controls->Add(this->ResultImageLabel);
				 this->flowLayoutPanel1->Controls->Add(this->checkBox1);
				 this->flowLayoutPanel1->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(136)));
				 this->flowLayoutPanel1->Location = System::Drawing::Point(3, 28);
				 this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
				 this->flowLayoutPanel1->Size = System::Drawing::Size(786, 286);
				 this->flowLayoutPanel1->TabIndex = 1;
				 // 
				 // pictureBox_SourceImage
				 // 
				 this->pictureBox_SourceImage->BackColor = System::Drawing::SystemColors::InactiveCaption;
				 this->pictureBox_SourceImage->Location = System::Drawing::Point(3, 3);
				 this->pictureBox_SourceImage->Name = L"pictureBox_SourceImage";
				 this->pictureBox_SourceImage->Size = System::Drawing::Size(256, 256);
				 this->pictureBox_SourceImage->TabIndex = 2;
				 this->pictureBox_SourceImage->TabStop = false;
				 // 
				 // pictureBox_OutputImage
				 // 
				 this->pictureBox_OutputImage->BackColor = System::Drawing::SystemColors::InactiveCaption;
				 this->pictureBox_OutputImage->Location = System::Drawing::Point(265, 3);
				 this->pictureBox_OutputImage->Name = L"pictureBox_OutputImage";
				 this->pictureBox_OutputImage->Size = System::Drawing::Size(256, 256);
				 this->pictureBox_OutputImage->TabIndex = 3;
				 this->pictureBox_OutputImage->TabStop = false;
				 // 
				 // pictureBox_Inverse
				 // 
				 this->pictureBox_Inverse->BackColor = System::Drawing::SystemColors::InactiveCaption;
				 this->pictureBox_Inverse->Location = System::Drawing::Point(527, 3);
				 this->pictureBox_Inverse->Name = L"pictureBox_Inverse";
				 this->pictureBox_Inverse->Size = System::Drawing::Size(256, 256);
				 this->pictureBox_Inverse->TabIndex = 3;
				 this->pictureBox_Inverse->TabStop = false;
				 // 
				 // label1
				 // 
				 this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(136)));
				 this->label1->Location = System::Drawing::Point(3, 262);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(126, 16);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"Source Image                                                                     "
					 L"                                                               ";
				 // 
				 // checkBox2
				 // 
				 this->checkBox2->Location = System::Drawing::Point(135, 265);
				 this->checkBox2->Name = L"checkBox2";
				 this->checkBox2->Size = System::Drawing::Size(128, 16);
				 this->checkBox2->TabIndex = 7;
				 this->checkBox2->Text = L"ScaleImage";
				 this->checkBox2->UseVisualStyleBackColor = true;
				 // 
				 // highPassFilter
				 // 
				 this->highPassFilter->AutoSize = true;
				 this->highPassFilter->Location = System::Drawing::Point(269, 265);
				 this->highPassFilter->Name = L"highPassFilter";
				 this->highPassFilter->Size = System::Drawing::Size(61, 16);
				 this->highPassFilter->TabIndex = 4;
				 this->highPassFilter->TabStop = true;
				 this->highPassFilter->Text = L"H-PASS";
				 this->highPassFilter->UseVisualStyleBackColor = true;
				 this->highPassFilter->CheckedChanged += gcnew System::EventHandler(this, &MyForm::highPassFilter_CheckedChanged);
				 // 
				 // LowPassFilter
				 // 
				 this->LowPassFilter->AutoSize = true;
				 this->LowPassFilter->Location = System::Drawing::Point(336, 265);
				 this->LowPassFilter->Name = L"LowPassFilter";
				 this->LowPassFilter->Size = System::Drawing::Size(60, 16);
				 this->LowPassFilter->TabIndex = 4;
				 this->LowPassFilter->TabStop = true;
				 this->LowPassFilter->Text = L"L-PASS";
				 this->LowPassFilter->UseVisualStyleBackColor = true;
				 this->LowPassFilter->CheckedChanged += gcnew System::EventHandler(this, &MyForm::LowPassFilter_CheckedChanged);
				 // 
				 // radius
				 // 
				 this->radius->Location = System::Drawing::Point(399, 262);
				 this->radius->Maximum = 127;
				 this->radius->Name = L"radius";
				 this->radius->Size = System::Drawing::Size(126, 19);
				 this->radius->TabIndex = 5;
				 this->radius->Value = 63;
				 this->radius->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
				 // 
				 // ResultImageLabel
				 // 
				 this->ResultImageLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(136)));
				 this->ResultImageLabel->Location = System::Drawing::Point(528, 262);
				 this->ResultImageLabel->Name = L"ResultImageLabel";
				 this->ResultImageLabel->Size = System::Drawing::Size(105, 19);
				 this->ResultImageLabel->TabIndex = 1;
				 this->ResultImageLabel->Text = L"Result Image                                                                     "
					 L"                                              ";
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
				 this->checkBox1->Location = System::Drawing::Point(639, 265);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(87, 16);
				 this->checkBox1->TabIndex = 6;
				 this->checkBox1->Text = L"HistogramEQ";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(792, 317);
				 this->Controls->Add(this->tableLayoutPanel1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MyForm";
				 this->Text = L"FourierTransform";
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->tableLayoutPanel1->PerformLayout();
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->flowLayoutPanel1->ResumeLayout(false);
				 this->flowLayoutPanel1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_SourceImage))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_OutputImage))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Inverse))->EndInit();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void loadImageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		openFileDialog1->ShowDialog();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		//將影像讀入並設儲存至DataManager的資料結構中
		Bitmap^ OriginalImage = gcnew Bitmap(openFileDialog1->FileName);
			
		double scaleH = 1.f;
		double scaleW = 1.f;
		int M = OriginalImage->Height;
		int N = OriginalImage->Width;

		if (checkBox2->Checked)
		{
			scaleH = IMAGE_SIZE / OriginalImage->Height;
			scaleW = IMAGE_SIZE / OriginalImage->Width;
			M = IMAGE_SIZE;
			N = IMAGE_SIZE;
		}		

		if (((M & (M - 1)) != 0)|| ((N & (N - 1)) != 0))
		{
			std::cout << "Image Height/Width is not Power of 2" << std::endl;
			return;
		}
		

		Bitmap^ Image = gcnew Bitmap(M, N);
		dataManager = new DataManager(M, N);

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				Color srcColor = OriginalImage->GetPixel(double(j) / scaleH, double(i) / scaleW); // 擷取每個點的顏色
				int srcGrey = srcColor.R*0.299 + srcColor.G*0.587 + srcColor.B*0.144; // 彩色三通道轉成灰階

				if (srcGrey > 255)srcGrey = 255;
				if (srcGrey < 0)srcGrey = 0;
				dataManager->SetPixel(j, i, srcGrey);
				Image->SetPixel(j, i, Color::FromArgb(srcGrey, srcGrey, srcGrey));
			}
		}

		pictureBox_SourceImage->Image = Image;

		FourierTransform();

		std::cout << "-Image has been loaded-" << std::endl;
	}
	private: void Historgram()
	{
		if (checkBox1->Checked)
		{
			int w = dataManager->GetImageWidth();
			int h = dataManager->GetImageHeight();

			fourierTransformMethod->equalizeHist(w, h, dataManager->GetOutputImage(), dataManager->GetHistogramEQImage());

			Bitmap^ OImage = gcnew Bitmap(w, h);
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					int valuePixeli = dataManager->GetHistogramEQImage()[i][j];
					if (valuePixeli > 255)
					{
						valuePixeli = 255;
					}
					else if (valuePixeli < 0)
					{
						valuePixeli = 0;
					}
					OImage->SetPixel(j, i, Color::FromArgb(valuePixeli, valuePixeli, valuePixeli));
				}
			}

			pictureBox_Inverse->Image = OImage;
		}
		else
		{
			int w = dataManager->GetImageWidth();
			int h = dataManager->GetImageHeight();

			Bitmap^ OImage = gcnew Bitmap(w, h);
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					int valuePixeli = dataManager->GetOutputImage()[i][j];
					if (valuePixeli > 255)
					{
						valuePixeli = 255;
					}
					else if (valuePixeli < 0)
					{
						valuePixeli = 0;
					}
					OImage->SetPixel(j, i, Color::FromArgb(valuePixeli, valuePixeli, valuePixeli));
				}
			}

			pictureBox_Inverse->Image = OImage;
		}
	
	}
	private: void FourierTransform()
	{
		if (dataManager == NULL) return;
		int w = dataManager->GetImageWidth();
		int h = dataManager->GetImageHeight();

		if (LowPassFilter->Checked)
			fourierTransformMethod->LowpassFilter(dataManager->Getfilter(), h, w, radius->Value);
		else if (highPassFilter->Checked)
			fourierTransformMethod->HighpassFilter(dataManager->Getfilter(), h, w, radius->Value);

		fastFourierTransform();
		inverseFastFourierTransform();
		Historgram();
	}

	private: Void fastFourierTransform() {

		int w = dataManager->GetImageWidth();
		int h = dataManager->GetImageHeight();

		// 利用傅立葉之平移性，平移頻率
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int valuePixeli = dataManager->GetInputImage()[i][j];
				valuePixeli = valuePixeli * pow((float)-1, (float)(i + j));
				dataManager->SetPixel(j, i, valuePixeli);
			}
		}

		//將算出頻率資訊傳入輸出影像
		fourierTransformMethod->FastFourierTransform(dataManager->GetInputImage(), dataManager->GetOutputImage(), dataManager->GetFreqReal(), dataManager->GetFreqImag(), h, w);
		Bitmap^ DFTImage = gcnew Bitmap(w, h);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int valuePixeli = dataManager->GetOutputImage()[i][j]*dataManager->Getfilter()[i][j];

				if (valuePixeli > 255)
				{
					valuePixeli = 255;
				}
				else if (valuePixeli < 0)
				{
					valuePixeli = 0;
				}
				DFTImage->SetPixel(j, i, Color::FromArgb(valuePixeli, valuePixeli, valuePixeli));
			}
		}
		pictureBox_OutputImage->Image = DFTImage;
	}
	private:Void inverseFastFourierTransform() {
		int w = dataManager->GetImageWidth();
		int h = dataManager->GetImageHeight();

		// 利用傅立葉之平移性，平移頻率
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int valuePixeli = dataManager->GetInputImage()[i][j];
				valuePixeli = valuePixeli * pow((float)-1, (float)(i + j));
				dataManager->SetPixel(j, i, valuePixeli);
			}
		}

		//將算出頻率資訊傳入輸出影像
		fourierTransformMethod->InverseFastFourierTransform(\
			dataManager->Getfilter(),\
			dataManager->GetInputImage(), dataManager->GetOutputImage(), \
			dataManager->GetFreqReal(), dataManager->GetFreqImag(), h, w);

		Bitmap^ DFTImage = gcnew Bitmap(w, h);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int valuePixeli = dataManager->GetOutputImage()[i][j];
				if (valuePixeli > 255)
				{
					valuePixeli = 255;
				}
				else if (valuePixeli < 0)
				{
					valuePixeli = 0;
				}
				DFTImage->SetPixel(j, i, Color::FromArgb(valuePixeli, valuePixeli, valuePixeli));
			}
		}
		pictureBox_Inverse->Image = DFTImage;
	}
	
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		Historgram();
	}
	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		FourierTransform();		
	}

	private: System::Void highPassFilter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		FourierTransform();
	}
	private: System::Void LowPassFilter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		FourierTransform();
	}
};
};

