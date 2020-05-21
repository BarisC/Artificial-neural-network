#pragma once

#include <random>
#include <math.h>
#include <time.h>

#define c 0.5
#define errorMax 0.1

static int size1, size2;
static double *p, *q, *w, *Z;

namespace YSAodev12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ýnitializeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deltaLearningContToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deltaLearningDiscToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  randomLineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  eXITToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  class1Box;
	private: System::Windows::Forms::CheckBox^  class2Box;
	private: System::Windows::Forms::CheckBox^  normalizeData;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^ label6;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ýnitializeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaLearningContToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaLearningDiscToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomLineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eXITToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->class1Box = (gcnew System::Windows::Forms::CheckBox());
			this->class2Box = (gcnew System::Windows::Forms::CheckBox());
			this->normalizeData = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->pictureBox1->Location = System::Drawing::Point(12, 51);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(650, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ýnitializeToolStripMenuItem,
					this->randomLineToolStripMenuItem, this->eXITToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// ýnitializeToolStripMenuItem
			// 
			this->ýnitializeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->deltaLearningContToolStripMenuItem,
					this->deltaLearningDiscToolStripMenuItem
			});
			this->ýnitializeToolStripMenuItem->Name = L"ýnitializeToolStripMenuItem";
			this->ýnitializeToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->ýnitializeToolStripMenuItem->Text = L"Initialize";
			// 
			// deltaLearningContToolStripMenuItem
			// 
			this->deltaLearningContToolStripMenuItem->Name = L"deltaLearningContToolStripMenuItem";
			this->deltaLearningContToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->deltaLearningContToolStripMenuItem->Text = L"Delta Learning(Cont.)";
			this->deltaLearningContToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deltaLearningContToolStripMenuItem_Click);
			// 
			// deltaLearningDiscToolStripMenuItem
			// 
			this->deltaLearningDiscToolStripMenuItem->Name = L"deltaLearningDiscToolStripMenuItem";
			this->deltaLearningDiscToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->deltaLearningDiscToolStripMenuItem->Text = L"Delta Learning(Disc.)";
			this->deltaLearningDiscToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deltaLearningDiscToolStripMenuItem_Click);
			// 
			// randomLineToolStripMenuItem
			// 
			this->randomLineToolStripMenuItem->Name = L"randomLineToolStripMenuItem";
			this->randomLineToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->randomLineToolStripMenuItem->Text = L"Random Line";
			this->randomLineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomLineToolStripMenuItem_Click);
			// 
			// eXITToolStripMenuItem
			// 
			this->eXITToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->eXITToolStripMenuItem->Name = L"eXITToolStripMenuItem";
			this->eXITToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->eXITToolStripMenuItem->Text = L"EXIT";
			this->eXITToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// class1Box
			// 
			this->class1Box->AutoSize = true;
			this->class1Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->class1Box->Location = System::Drawing::Point(452, 50);
			this->class1Box->Name = L"class1Box";
			this->class1Box->Size = System::Drawing::Size(69, 21);
			this->class1Box->TabIndex = 2;
			this->class1Box->Text = L"Class1";
			this->class1Box->UseVisualStyleBackColor = true;
			// 
			// class2Box
			// 
			this->class2Box->AutoSize = true;
			this->class2Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->class2Box->Location = System::Drawing::Point(452, 77);
			this->class2Box->Name = L"class2Box";
			this->class2Box->Size = System::Drawing::Size(69, 21);
			this->class2Box->TabIndex = 3;
			this->class2Box->Text = L"Class2";
			this->class2Box->UseVisualStyleBackColor = true;
			// 
			// normalizeData
			// 
			this->normalizeData->AutoSize = true;
			this->normalizeData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->normalizeData->Location = System::Drawing::Point(452, 120);
			this->normalizeData->Name = L"normalizeData";
			this->normalizeData->Size = System::Drawing::Size(124, 21);
			this->normalizeData->TabIndex = 4;
			this->normalizeData->Text = L"Normalize Data";
			this->normalizeData->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(449, 167);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 17);
			this->label1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(449, 189);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 17);
			this->label2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(521, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 17);
			this->label3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(449, 254);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 17);
			this->label4->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(449, 284);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 17);
			this->label5->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button1->Location = System::Drawing::Point(482, 367);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 38);
			this->button1->TabIndex = 11;
			this->button1->Text = L"REFRESH";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button1_MouseClick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(533, 439);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 15);
			this->label6->TabIndex = 12;
			this->label6->Text = L"by Barýþcan ÇORUH";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 463);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->normalizeData);
			this->Controls->Add(this->class2Box);
			this->Controls->Add(this->class1Box);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Yapay Sinir Aðý";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: double *normalize(double totalInput[]){

			 int size = size1 + size2;
			 double sD1 = 0, sD2 = 0, average1 = 0, average2 = 0, *Z;
			 double temp1 = 0, temp2 = 0;

			 if (size1 > 0 && size2 > 0){

				 Z = new double[size * 3];

				 for (int i = 0; i < size * 3; i += 3)
				 {
					 average1 += totalInput[i];
					 average2 += totalInput[i + 1];
				 }

				 average1 = average1 / double(size);
				 average2 = average2 / double(size);

				 for (int j = 0; j < size * 3; j += 3){
					 temp1 += pow(totalInput[j] - average1, 2);
					 temp2 += pow(totalInput[j + 1] - average2, 2);
				 }

				 sD1 = sqrt(temp1 / (size - 1));
				 sD2 = sqrt(temp2 / (size - 1));

				 for (int k = 0; k < size * 3; k += 3){
					 Z[k] = (totalInput[k] - average1) / sD1;
					 Z[k + 1] = (totalInput[k + 1] - average2) / sD2;
					 Z[k + 2] = totalInput[k + 2];
				 }

				 return Z;
			 }
}

private: void drawAgain(){

			 if (normalizeData->Checked){
				 
				 int x = 0, y = 0, multiplier = 50;

				 Pen^ pen1 = gcnew Pen(Color::Black, 3.0f);
				 for (int i = 0; i < size1 * 3; i += 3){
					 x = (Z[i] * multiplier) + (pictureBox1->Width / 2);
					 y = pictureBox1->Height / 2 - (Z[i + 1] * multiplier);
					 pictureBox1->CreateGraphics()->DrawLine(pen1, x - 5, y, x + 5, y);
					 pictureBox1->CreateGraphics()->DrawLine(pen1, x, y - 5, x, y + 5);
				 }
				 Pen^ pen2 = gcnew Pen(Color::Red, 3.0f);
				 for (int j = size1 * 3; j < (size1 + size2) * 3; j += 3){
					 x = (Z[j] * multiplier) + (pictureBox1->Width / 2);
					 y = pictureBox1->Height / 2 - (Z[j + 1] * multiplier);
					 pictureBox1->CreateGraphics()->DrawLine(pen2, x - 5, y, x + 5, y);
					 pictureBox1->CreateGraphics()->DrawLine(pen2, x, y - 5, x, y + 5);
				 }
			 }
			 else{

				 int x = 0, y = 0;

				 if (size1 > 0){
					 Pen^ pen1 = gcnew Pen(Color::Black, 3.0f);
					 for (int i = 0; i < size1 * 3; i += 3){
						 x = int(p[i]) + (pictureBox1->Width) / 2;
						 y = (pictureBox1->Height) - (int(p[i + 1]) + (pictureBox1->Height) / 2);
						 pictureBox1->CreateGraphics()->DrawLine(pen1, x - 5, y, x + 5, y);
						 pictureBox1->CreateGraphics()->DrawLine(pen1, x, y - 5, x, y + 5);
					 }
				 }

				 if (size2 > 0){
					 Pen^ pen2 = gcnew Pen(Color::Red, 3.0f);
					 for (int j = 0; j < size2 * 3; j += 3){
						 x = int(q[j]) + (pictureBox1->Width) / 2;
						 y = (pictureBox1->Height) - (int(q[j + 1]) + (pictureBox1->Height) / 2);
						 pictureBox1->CreateGraphics()->DrawLine(pen2, x, y - 5, x, y + 5);
						 pictureBox1->CreateGraphics()->DrawLine(pen2, x - 5, y, x + 5, y);
					 }
				 }
			 }
}

private: void drawAgain2(){

			 int x = 0, y = 0;
			 double multiplier = 50.0;

			 Pen^ pen1 = gcnew Pen(Color::Black, 3.0f);
			 for (int i = 0; i < size1 * 3; i += 3){
				 x = (Z[i] * multiplier) + (pictureBox1->Width / 2);
				 y = pictureBox1->Height / 2 - (Z[i + 1] * multiplier);
				 pictureBox1->CreateGraphics()->DrawLine(pen1, x - 5, y, x + 5, y);
				 pictureBox1->CreateGraphics()->DrawLine(pen1, x, y - 5, x, y + 5);
			 }
			 Pen^ pen2 = gcnew Pen(Color::Red, 3.0f);
			 for (int j = size1 * 3; j < (size1 + size2) * 3; j += 3){
				 x = (Z[j] * multiplier) + (pictureBox1->Width / 2);
				 y = pictureBox1->Height / 2 - (Z[j + 1] * multiplier);
				 pictureBox1->CreateGraphics()->DrawLine(pen2, x - 5, y, x + 5, y);
				 pictureBox1->CreateGraphics()->DrawLine(pen2, x, y - 5, x, y + 5);
			 }
}

private: void randomLine(){

				 double min_x, min_y, max_x, max_y;
				 Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

				 w = new double[3];
				 srand(time(0));
				 for (unsigned int i = 0; i < 3; i++)
					 w[i] = ((double)rand() / (RAND_MAX));

				 pictureBox1->Refresh();

				 min_x = pictureBox1->Width / -2;
				 min_y = (-w[2] - w[0] * min_x) / w[1];
				 max_x = pictureBox1->Width / 2;
				 max_y = (-w[2] - w[0] * max_x) / w[1];

				 drawAgain();

				 pictureBox1->CreateGraphics()->DrawLine(pen, int(min_x) + pictureBox1->Width / 2, pictureBox1->Height / 2 - int(min_y), int(max_x) + pictureBox1->Width / 2, pictureBox1->Height / 2 - int(max_y));

}

private: void drawLine(){

			 double min_x, min_y, max_x, max_y;
			 Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			 pictureBox1->Refresh();

			 min_x = pictureBox1->Width / -2;
			 min_y = (-w[2] - w[0] * min_x) / w[1];
			 max_x = pictureBox1->Width / 2;
			 max_y = (-w[2] - w[0] * max_x) / w[1];

			 drawAgain();
			 
			 pictureBox1->CreateGraphics()->DrawLine(pen, int(min_x) + pictureBox1->Width / 2, pictureBox1->Height / 2 - int(min_y), int(max_x) + pictureBox1->Width / 2, pictureBox1->Height / 2 - int(max_y));
}

private: void drawLine2(){

			 double min_x, min_y, max_x, max_y;
			 Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

			 pictureBox1->Refresh();

			 min_x = pictureBox1->Width / -2;
			 min_y = (-w[2] - w[0] * min_x) / w[1];
			 max_x = pictureBox1->Width / 2;
			 max_y = (-w[2] - w[0] * max_x) / w[1];

			 drawAgain2();

			 pictureBox1->CreateGraphics()->DrawLine(pen, int(min_x) + pictureBox1->Width / 2, pictureBox1->Height / 2 - int(min_y), int(max_x) + pictureBox1->Width / 2, pictureBox1->Height / 2 - int(max_y));
}

private: void discLearning(){

			 double d1 = 1.0, d2 = -1.0;
			 double error = 0;
			 double net, fnet;
			 int step = 1, cycle = 1;

			 if (normalizeData->Checked){  //normalize

				 double *inputs;

				 inputs = new double[(size1 + size2) * 3];
				 for (int a = 0; a < size1 * 3; a++) inputs[a] = p[a];
				 for (int b = 0; b < size2 * 3; b++) inputs[b + size1 * 3] = q[b];
				 Z = new double[(size1 + size2) * 3];
				 Z = normalize(inputs);

				 do{
					 if (step == size1 + size2 + 1){
						 error = 0;
						 step = 1;
						 cycle++;
					 }

					 for (int i = 0; i < size1; i++){

						 net = w[0] * Z[i * 3] + w[1] * Z[i * 3 + 1] + w[2] * Z[i * 3 + 2];

						 if (net >= 0) fnet = 1;
						 else fnet = -1;

						 w[0] = w[0] + c*(d1 - fnet) * Z[i * 3];
						 w[1] = w[1] + c*(d1 - fnet) * Z[i * 3 + 1];
						 w[2] = w[2] + c*(d1 - fnet) * Z[i * 3 + 2];

						 error += 0.5 * pow((d1 - fnet), 2);
						 step++;
						 drawLine();

					 }

					 for (int i = size1; i < size1 + size2; i++){

						 net = w[0] * Z[i * 3] + w[1] * Z[i * 3 + 1] + w[2] * Z[i * 3 + 2];

						 if (net >= 0) fnet = 1;
						 else fnet = -1;

						 w[0] = w[0] + c*(d2 - fnet) * Z[i * 3];
						 w[1] = w[1] + c*(d2 - fnet) * Z[i * 3 + 1];
						 w[2] = w[2] + c*(d2 - fnet) * Z[i * 3 + 2];

						 error += 0.5 * pow(d2 - fnet, 2);
						 step++;
						 drawLine();

					 }
				 } while (error != 0);

			 }
			 else{

				 do{

					 if (step == size1 + size2 + 1){
						 error = 0;
						 step = 1;
						 cycle++;
					 }

					 for (int i = 0; i < size1; i++){
						 net = w[0] * p[i * 3] + w[1] * p[i * 3 + 1] + w[2] * p[i * 3 + 2];

						 if (net >= 0) fnet = 1;
						 else fnet = -1;

						 w[0] = w[0] + c * (d1 - fnet) * p[i * 3];
						 w[1] = w[1] + c * (d1 - fnet) * p[i * 3 + 1];
						 w[2] = w[2] + c * (d1 - fnet) * p[i * 3 + 2];

						 error += abs(d1 - fnet) * 0.5;
						 step++;
						 drawLine();
					 }

					 for (int i = 0; i < size2; i++){
						 net = w[0] * q[i * 3] + w[1] * q[i * 3 + 1] + w[2] * q[i * 3 + 2];

						 if (net > 0) fnet = 1;
						 else fnet = -1;

						 w[0] = w[0] + c * (d2 - fnet) * q[i * 3];
						 w[1] = w[1] + c * (d2 - fnet) * q[i * 3 + 1];
						 w[2] = w[2] + c * (d2 - fnet) * q[i * 3 + 2];

						 error += abs(d2 - fnet) * 0.5;
						 step++;
						 drawLine();

					 }

				 } while (error != 0);
			 }		 

			 label4->Text = "Training is completed.";
			 label5->Text = "Cycle: " + Convert::ToString(cycle);

}

private: void contLearning(){

			 double d1 = 1.0, d2 = -1.0;
			 double error = 0, alfa = 1;
			 double net, fnet, tnet;
			 int step = 1, cycle = 1;
			 double *inputs;

			 inputs = new double[(size1 + size2) * 3];
			 for (int a = 0; a < size1 * 3; a++) inputs[a] = p[a];
			 for (int b = 0; b < size2 * 3; b++) inputs[b + size1 * 3] = q[b];

			 Z = new double[(size1 + size2) * 3];
			 Z = normalize(inputs);

			 do{
				 
				 if (step == size1 + size2 + 1){
					 error = 0;
					 step = 1;
					 cycle++;
				 }

				 for (int i = 0; i < size1; i++){

					 net = w[0] * Z[i * 3] + w[1] * Z[i * 3 + 1] + w[2] * Z[i * 3 + 2];

					 fnet = ((2 / (1 + exp(-alfa*net))) - 1);
					 tnet = (0.5) * (1 - pow(fnet, 2));

					 w[0] = w[0] + c*(d1 - fnet) * tnet * Z[i * 3];
					 w[1] = w[1] + c*(d1 - fnet) * tnet * Z[i * 3 + 1];
					 w[2] = w[2] + c*(d1 - fnet) * tnet * Z[i * 3 + 2];

					 error += 0.5 * pow((d1 - fnet), 2);
					 step++;
					 drawLine2();
				 
				 }

				 for (int i = size1; i < size1 + size2; i++){

					 net = w[0] * Z[i * 3] + w[1] * Z[i * 3 + 1] + w[2] * Z[i * 3 + 2];

					 fnet = ((2 / (1 + exp(-alfa*net))) - 1);
					 tnet = (0.5) * (1 - pow(fnet, 2));

					 w[0] = w[0] + c*(d2 - fnet) * tnet * Z[i * 3];
					 w[1] = w[1] + c*(d2 - fnet) * tnet * Z[i * 3 + 1];
					 w[2] = w[2] + c*(d2 - fnet) * tnet * Z[i * 3 + 2];

					 error += 0.5 * pow(d2 - fnet, 2);
					 step++;
					 drawLine2();

				 }

				 error = error / (step - 1);

			 } while (error >= errorMax);

		     label4->Text = "Training is completed.";
			 label5->Text = "Cycle: " + Convert::ToString(cycle);

}

private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 if (class1Box->Checked && class2Box->Checked){
					 MessageBox::Show("Ýkisi de seçilemez!");
					 class1Box->Checked = false;
					 class2Box->Checked = false;
				 }
				 else{
					 if (class1Box->Checked || class2Box->Checked){
						 if (class1Box->Checked){

							 Pen^ pen = gcnew Pen(Color::Black, 3.0f);

							 int temp_x, temp_y;
							 double x1, x2;
							 temp_x = (System::Convert::ToInt32(e->X));
							 temp_y = (System::Convert::ToInt32(e->Y));
							 x1 = (double)(temp_x - (pictureBox1->Width >> 1));
							 x2 = (double)((pictureBox1->Height >> 1) - temp_y);

							 if (size1 == 0){
								 size1 = 1;
								 p = new double[3];
								 p[0] = x1;
								 p[1] = x2;
								 p[2] = 1.0;
								 label1->Text = "x1: " + (Convert::ToString(p[0]));
								 label2->Text = "x2: " + (Convert::ToString(p[1]));
							 }
							 else{
								 double *temp;
								 temp = p;
								 size1++;
								 p = new double[size1 * 3];
								 for (int i = 0; i < (size1 - 1) * 3; i++)
									 p[i] = temp[i];
								 p[(size1 - 1) * 3] = x1;
								 p[(size1 - 1) * 3 + 1] = x2;
								 p[(size1 - 1) * 3 + 2] = 1.0;
								 delete temp;
								 label1->Text = "x1: " + (Convert::ToString(p[(size1 - 1) * 3]));
								 label2->Text = "x2: " + (Convert::ToString(p[(size1 - 1) * 3 + 1]));
							 }

							 label3->Text = "Class1  Adet: " + (Convert::ToString(size1));

							 pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
							 pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
						 }
						 else{

							 Pen^ pen = gcnew Pen(Color::Red, 3.0f);

							 int temp_x, temp_y;
							 double x1, x2;
							 temp_x = (System::Convert::ToInt32(e->X));
							 temp_y = (System::Convert::ToInt32(e->Y));
							 x1 = (double)(temp_x - (pictureBox1->Width >> 1));
							 x2 = (double)((pictureBox1->Height >> 1) - temp_y);

							 if (size2 == 0){
								 size2 = 1;
								 q = new double[3];
								 q[0] = x1;
								 q[1] = x2;
								 q[2] = 1.0;
								 label1->Text = "x1: " + (Convert::ToString(q[0]));
								 label2->Text = "x2: " + (Convert::ToString(q[1]));
							 }
							 else{
								 double *temp;
								 temp = q;
								 size2++;
								 q = new double[size2 * 3];
								 for (int i = 0; i < (size2 - 1) * 3; i++)
									 q[i] = temp[i];
								 q[(size2 - 1) * 3] = x1;
								 q[(size2 - 1) * 3 + 1] = x2;
								 q[(size2 - 1) * 3 + 2] = 1.0;
								 delete temp;
								 label1->Text = "x1: " + (Convert::ToString(q[(size2 - 1) * 3]));
								 label2->Text = "x2: " + (Convert::ToString(q[(size2 - 1) * 3 + 1]));
							 }

							 label3->Text = "Class2  Adet: " + (Convert::ToString(size2));

							 pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
							 pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
						 }
					 }
				 }
}

private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 Pen^ pen = gcnew Pen(Color::Black, 4.0f);
				 e->Graphics->DrawLine(pen, 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
				 e->Graphics->DrawLine(pen, pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
}

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 exit(0);
}

private: System::Void randomLineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 randomLine();
}

private: System::Void deltaLearningDiscToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 discLearning();
}

private: System::Void deltaLearningContToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 contLearning();
}

private: System::Void button1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 size1 = 0;
			 size2 = 0;

			 pictureBox1->Refresh();

			 label1->Text = "";
			 label2->Text = "";
			 label3->Text = "";
			 label4->Text = "";
			 label5->Text = "";
			 
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}


