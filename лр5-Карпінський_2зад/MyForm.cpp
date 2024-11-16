#pragma once

namespace MatrixTransformationApp {

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

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Button^ buttonTransform;
        System::Windows::Forms::TextBox^ resultBox;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->buttonTransform = (gcnew System::Windows::Forms::Button());
            this->resultBox = (gcnew System::Windows::Forms::TextBox());

            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(20, 20);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(180, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"¬вед≥ть елементи матриц≥ (3x3):";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(20, 40);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(200, 60);
            this->textBox1->TabIndex = 1;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(20, 110);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(50, 13);
            this->label2->TabIndex = 2;
            this->label2->Text = L"–езультат:";
            // 
            // buttonTransform
            // 
            this->buttonTransform->Location = System::Drawing::Point(20, 140);
            this->buttonTransform->Name = L"buttonTransform";
            this->buttonTransform->Size = System::Drawing::Size(200, 23);
            this->buttonTransform->TabIndex = 3;
            this->buttonTransform->Text = L"«м≥нити матрицю";
            this->buttonTransform->UseVisualStyleBackColor = true;
            this->buttonTransform->Click += gcnew System::EventHandler(this, &MyForm::buttonTransform_Click);
            // 
            // resultBox
            // 
            this->resultBox->Location = System::Drawing::Point(20, 130);
            this->resultBox->Multiline = true;
            this->resultBox->Name = L"resultBox";
            this->resultBox->Size = System::Drawing::Size(200, 60);
            this->resultBox->TabIndex = 4;
            // 
            // MyForm
            // 
            this->ClientSize = System::Drawing::Size(240, 210);
            this->Controls->Add(this->resultBox);
            this->Controls->Add(this->buttonTransform);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm";
            this->Text = L"ѕеретворенн€ матриц≥";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        void TransformMatrix(array<array<int>^>^ matrix, int rows, int cols) {
            int minRow = -1, minCol = -1;
            int minVal = 0;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (matrix[i][j] < minVal) {
                        minVal = matrix[i][j];
                        minRow = i;
                        minCol = j;
                    }
                }
            }

            for (int j = 0; j < cols; j++) {
                matrix[minRow][j] = 0;
            }

            for (int i = 0; i < rows; i++) {
                matrix[i][minCol] = 0;
            }
        }

    private: System::Void buttonTransform_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ inputText = textBox1->Text;
        array<String^>^ rows = inputText->Split('\n');
        array<array<int>^>^ matrix = gcnew array<array<int>^>(3);
        for (int i = 0; i < 3; i++) {
            array<String^>^ elements = rows[i]->Split(' ');
            matrix[i] = gcnew array<int>(3);
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = Int32::Parse(elements[j]);
            }
        }

        TransformMatrix(matrix, 3, 3);

        String^ resultText = "";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                resultText += matrix[i][j].ToString() + " ";
            }
            resultText += "\r\n";
        }

        resultBox->Text = resultText;
    }
    };
}
