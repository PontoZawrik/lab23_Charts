#pragma once
#include "SecondForm.h"

namespace tasks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Создать таблицу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(13, 43);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(343, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(384, 300);
			this->dataGridView1->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(137, 349);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 3;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 352);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Шаг вычислений:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(773, 398);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		SecondForm^ f = gcnew SecondForm();
		f->Show();
	}

	private: DataTable^ table;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		table = gcnew DataTable();
		table->Columns->Add("x", double::typeid);
		table->Columns->Add("f(x)", double::typeid);

		this->textBox1->Text = "0,1";
		DataRow^ row;
		for (double x = 0; x <= 5; x += 0.1) {
			row = table->NewRow();
			row["x"] = x;
			row["f(x)"] = (2 * Math::Pow(x, 2) - 3 * x + 1) / (1 - 2 * x);
			table->Rows->Add(row);
		}

		chart1->DataSource = table;
		dataGridView1->DataSource = table;

		chart1->Titles->Add("График функции");
		chart1->Series["Series1"]->XValueMember = "x";
		chart1->Series["Series1"]->YValueMembers = "f(x)";
		chart1->Series["Series1"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		chart1->Series["Series1"]->Color = Color::Red;
		chart1->Series["Series1"]->IsVisibleInLegend = false;
		chart1->DataBind();
	}

	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			try {
				double a = Double::Parse(this->textBox1->Text);
				if (a > 0 && a <= 5) {
					e->SuppressKeyPress = true; // Убирает звук и \n при нажатии

					table->Rows->Clear();
					DataRow^ row;
					for (double x = 0; x <= 5; x += a) {
						row = table->NewRow();
						row["x"] = x;
						row["f(x)"] = (2 * Math::Pow(x, 2) - 3 * x + 1) / (1 - 2 * x);
						table->Rows->Add(row);
					}
					chart1->DataBind();
				}
				else {
					MessageBox::Show("Неверный диапазон значений.", "Внимание");
				}
			}
			catch (System::ArgumentNullException^ e) {
				MessageBox::Show(this, "Пустая ссылка.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (System::FormatException^ e) {
				MessageBox::Show(this, "Введите вещественное число.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			catch (System::OverflowException^ e) {
				MessageBox::Show(this, "Введите число подходящего размера.", "Слишком большое или маленькое число", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			}
		}

	}
};
}
