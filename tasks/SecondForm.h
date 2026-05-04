#pragma once

namespace tasks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SecondForm
	/// </summary>
	public ref class SecondForm : public System::Windows::Forms::Form
	{
	public:
		SecondForm(void)
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
		~SecondForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(13, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(360, 229);
			this->dataGridView1->TabIndex = 0;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(392, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &SecondForm::chart1_Click);
			// 
			// SecondForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 340);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"SecondForm";
			this->Text = L"SecondForm";
			this->Load += gcnew System::EventHandler(this, &SecondForm::SecondForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SecondForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Толстик Дмитрий Т-491";

		DataTable^ table = gcnew DataTable();
		table->Columns->Add("Название", String::typeid);
		table->Columns->Add("Вес", double::typeid);

		DataRow^ row = table->NewRow();
		row["Название"] = "Apple iPhone 16 Pro 128GB";
		row["Вес"] = 0.2;
		table->Rows->Add(row);
		row = table->NewRow();
		row["Название"] = "Infinix Hot 60i X6728 8GB/256GB";
		row["Вес"] = 0.23;
		table->Rows->Add(row);
		row = table->NewRow();
		row["Название"] = "Apple iPhone 15 256GB";
		row["Вес"] = 0.19;
		table->Rows->Add(row);
		row = table->NewRow();
		row["Название"] = "Xiaomi Redmi Note 15 Pro+ 5G 8GB/256GB";
		row["Вес"] = 0.25;
		table->Rows->Add(row);
		row = table->NewRow();
		row["Название"] = "Apple iPhone 17 256GB";
		row["Вес"] = 0.22;
		table->Rows->Add(row);

		dataGridView1->DataSource = table;
		chart1->DataSource = table;

		chart1->Titles->Add("Вес смартфонов");
		chart1->Series["Series1"]->XValueMember = "Название";
		chart1->Series["Series1"]->YValueMembers = "Вес";
		chart1->Series["Series1"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
		chart1->Series["Series1"]->Color = Color::Green;
		chart1->Series["Series1"]->IsVisibleInLegend = false;
		chart1->DataBind();
	}

	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
		chart1->DataBind();
	}
	};
}
