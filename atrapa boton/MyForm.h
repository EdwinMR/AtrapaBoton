#pragma once

namespace atrapaboton {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			incializacion();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		Button ^btnboton1;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 248);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		void incializacion()
		{
			//inicializacion de atributos
			btnboton1 = gcnew Button();
			//configuracion de atributos
			btnboton1->Location = Point(95, 113);
			btnboton1->Size = Drawing::Size(100, 23);
			btnboton1->Text = L"chase me";
			btnboton1->Visible = true;
			btnboton1->MouseMove += gcnew MouseEventHandler(this, &MyForm::mover);
			btnboton1->Click += gcnew EventHandler(this, &MyForm::click);
			//agregar lista de controles
			Controls->Add(btnboton1);
		}
		Void mover(System::Object^  sender, MouseEventArgs^  e)
		{
			Random ^r = gcnew Random();
			int x = (int)(this->ClientRectangle.Right * r->NextDouble()) - 20;
			int y = (int)(this->ClientRectangle.Bottom * r->NextDouble()) - 10;
			btnboton1->Location = Point(x, y);
		}
		Void click(Object ^remitente, EventArgs ^e)
		{
			btnboton1->Text = L"you´d catch me";
			btnboton1->ForeColor = Drawing::Color::Red;
		}
	};
}
