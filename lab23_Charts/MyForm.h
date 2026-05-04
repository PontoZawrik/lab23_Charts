#pragma once
#include "SecondForm.h"

namespace lab23Charts {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(121, 24);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(26, 69);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(344, 242);
			this->dataGridView1->TabIndex = 2;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(397, 24);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(709, 391);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double a;
		try {
			a = Double::Parse(this->textBox1->Text);
			SecondForm^ f = gcnew SecondForm(a);
			f->Show();
		}
		catch (System::ArgumentNullException^ e) {
			MessageBox::Show(this, "ѕуста€ ссылка.", "¬нимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (System::FormatException^ e) {
			MessageBox::Show(this, "¬ведите вещественное число.", "¬нимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		catch (System::OverflowException^ e) {
			MessageBox::Show(this, "¬ведите число подход€щего размера.", "—лишком большое или маленькое число", MessageBoxButtons::OK, MessageBoxIcon::Stop);
		}
	}

	private: bool cilindr;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		cilindr = false;
		this->Text = "ўелкните на график";

		DataTable^ table = gcnew DataTable();
		table->Columns->Add("ћес€ц", String::typeid);
		table->Columns->Add("ќбъЄм продаж", long::typeid);

		DataRow^ row = table->NewRow();
		row["ћес€ц"] = "ћай";
		row["ќбъЄм продаж"] = 15;
		table->Rows->Add(row);
		row = table->NewRow();
		row["ћес€ц"] = "»юнь";
		row["ќбъЄм продаж"] = 90;
		table->Rows->Add(row);
		row = table->NewRow();
		row["ћес€ц"] = "»юль";
		row["ќбъЄм продаж"] = 65;
		table->Rows->Add(row);
		row = table->NewRow();
		row["ћес€ц"] = "јвгуст";
		row["ќбъЄм продаж"] = 40;
		table->Rows->Add(row);
		row = table->NewRow();
		row["ћес€ц"] = "—ент€брь";
		row["ќбъЄм продаж"] = 80;
		table->Rows->Add(row);

		dataGridView1->DataSource = table;
		chart1->DataSource = table;

		chart1->Titles->Add("ќбъЄм продаж по мес€цам");
		chart1->Series["Series1"]->XValueMember = "ћес€ц";
		chart1->Series["Series1"]->YValueMembers = "ќбъЄм продаж";
		chart1->Series["Series1"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
		chart1->Series["Series1"]->Color = Color::Aqua;
		chart1->Series["Series1"]->IsVisibleInLegend = false;
		chart1->DataBind();
	}

	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
		cilindr = !cilindr;
		if (cilindr) {
			chart1->Series["Series1"]["DrawingStyle"] = "Cylinder";
		}
		else {
			chart1->Series["Series1"]["DrawingStyle"] = "Default";
		}
		chart1->DataBind();
	}
};
}
