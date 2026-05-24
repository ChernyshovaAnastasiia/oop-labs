#pragma once
#include "GameLogic.h"
#include <msclr\marshal_cppstd.h>

namespace BullsAndCows {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	private:
		GameState* gameState;

	public:
		MainForm(void)
		{
			InitializeComponent();
			srand((unsigned)time(0));
			gameState = new GameState();
			startNewGame(gameState);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxGuess;
	private: System::Windows::Forms::Button^ buttonCheck;
	private: System::Windows::Forms::ListBox^ listBoxHistory;
	private: System::Windows::Forms::Button^ buttonNewGame;
	private: System::Windows::Forms::Button^ buttonAuthor;
	private: System::Windows::Forms::Button^ buttonGiveUp;
	private: System::Windows::Forms::Button^ buttonRules;
	private: System::Windows::Forms::Button^ buttonExit;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->textBoxGuess = (gcnew System::Windows::Forms::TextBox());
			this->buttonCheck = (gcnew System::Windows::Forms::Button());
			this->listBoxHistory = (gcnew System::Windows::Forms::ListBox());
			this->buttonNewGame = (gcnew System::Windows::Forms::Button());
			this->buttonAuthor = (gcnew System::Windows::Forms::Button());
			this->buttonGiveUp = (gcnew System::Windows::Forms::Button());
			this->buttonRules = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxGuess
			// 
			this->textBoxGuess->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->textBoxGuess->Location = System::Drawing::Point(37, 146);
			this->textBoxGuess->Multiline = true;
			this->textBoxGuess->Name = L"textBoxGuess";
			this->textBoxGuess->Size = System::Drawing::Size(114, 48);
			this->textBoxGuess->TabIndex = 0;
			// 
			// buttonCheck
			// 
			this->buttonCheck->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonCheck->Location = System::Drawing::Point(215, 412);
			this->buttonCheck->Name = L"buttonCheck";
			this->buttonCheck->Size = System::Drawing::Size(159, 47);
			this->buttonCheck->TabIndex = 1;
			this->buttonCheck->Text = L"Перевірити";
			this->buttonCheck->UseVisualStyleBackColor = false;
			this->buttonCheck->Click += gcnew System::EventHandler(this, &MainForm::buttonCheck_Click);
			// 
			// listBoxHistory
			// 
			this->listBoxHistory->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->listBoxHistory->FormattingEnabled = true;
			this->listBoxHistory->ItemHeight = 25;
			this->listBoxHistory->Location = System::Drawing::Point(177, 77);
			this->listBoxHistory->Name = L"listBoxHistory";
			this->listBoxHistory->Size = System::Drawing::Size(396, 179);
			this->listBoxHistory->TabIndex = 2;
			// 
			// buttonNewGame
			// 
			this->buttonNewGame->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonNewGame->Location = System::Drawing::Point(407, 412);
			this->buttonNewGame->Name = L"buttonNewGame";
			this->buttonNewGame->Size = System::Drawing::Size(166, 47);
			this->buttonNewGame->TabIndex = 3;
			this->buttonNewGame->Text = L"Нова гра";
			this->buttonNewGame->UseVisualStyleBackColor = false;
			this->buttonNewGame->Click += gcnew System::EventHandler(this, &MainForm::buttonNewGame_Click);
			// 
			// buttonAuthor
			// 
			this->buttonAuthor->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonAuthor->Location = System::Drawing::Point(23, 13);
			this->buttonAuthor->Name = L"buttonAuthor";
			this->buttonAuthor->Size = System::Drawing::Size(148, 45);
			this->buttonAuthor->TabIndex = 4;
			this->buttonAuthor->Text = L"Автор";
			this->buttonAuthor->UseVisualStyleBackColor = false;
			this->buttonAuthor->Click += gcnew System::EventHandler(this, &MainForm::buttonAuthor_Click);
			// 
			// buttonGiveUp
			// 
			this->buttonGiveUp->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonGiveUp->Location = System::Drawing::Point(12, 412);
			this->buttonGiveUp->Name = L"buttonGiveUp";
			this->buttonGiveUp->Size = System::Drawing::Size(159, 47);
			this->buttonGiveUp->TabIndex = 5;
			this->buttonGiveUp->Text = L"Здатися";
			this->buttonGiveUp->UseVisualStyleBackColor = false;
			this->buttonGiveUp->Click += gcnew System::EventHandler(this, &MainForm::buttonGiveUp_Click);
			// 
			// buttonRules
			// 
			this->buttonRules->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonRules->Location = System::Drawing::Point(178, 13);
			this->buttonRules->Name = L"buttonRules";
			this->buttonRules->Size = System::Drawing::Size(132, 45);
			this->buttonRules->TabIndex = 6;
			this->buttonRules->Text = L"Правила";
			this->buttonRules->UseVisualStyleBackColor = false;
			this->buttonRules->Click += gcnew System::EventHandler(this, &MainForm::buttonRules_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonExit->Location = System::Drawing::Point(487, 12);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(86, 45);
			this->buttonExit->TabIndex = 7;
			this->buttonExit->Text = L"Вихід";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MainForm::buttonExit_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(585, 471);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonRules);
			this->Controls->Add(this->buttonGiveUp);
			this->Controls->Add(this->buttonAuthor);
			this->Controls->Add(this->buttonNewGame);
			this->Controls->Add(this->listBoxHistory);
			this->Controls->Add(this->buttonCheck);
			this->Controls->Add(this->textBoxGuess);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCheck_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ input = textBoxGuess->Text;
		if (input->Length != 4) {
			MessageBox::Show("Введіть рівно 4 цифри.", "Помилка");
			return;
		}

		std::string unmanagedInput = msclr::interop::marshal_as<std::string>(input);
		const char* guessChars = unmanagedInput.c_str();

		int b = 0, c = 0;
		Attempt currentAttempt;

		checkGuess(gameState, guessChars, b, c, &currentAttempt);

		String^ resultStr = String::Format("Число: {0} | Бики: {1}, Корови: {2}",
			input, currentAttempt.bulls, currentAttempt.cows);
		listBoxHistory->Items->Add(resultStr);

		if (currentAttempt.cows == 4) {
			MessageBox::Show("Вітаю! Ви вгадали число за " + gameState->attemptsCount.ToString() + " спроб.", "Перемога");
			saveHistoryToFile(gameState, "game_history.txt");
		}
		textBoxGuess->Clear();
	}
private: System::Void buttonNewGame_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Розпочати нову гру?", "Підтвердження", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
		startNewGame(gameState);
		listBoxHistory->Items->Clear();
		MessageBox::Show("Комп'ютер загадав нове число.", "Увага");
	}
}
private: System::Void buttonAuthor_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Роботу виконала:\nСтудентка групи КН-1225а\nЧернишова Анастасія", "Про автора");
}
private: System::Void buttonGiveUp_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ secretStr = gcnew String(gameState->secret);
	MessageBox::Show("Ви здалися. Загадане число: " + secretStr, "Кінець гри");

	startNewGame(gameState);
	listBoxHistory->Items->Clear();
	textBoxGuess->Clear();
}
private: System::Void buttonRules_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ rules = "Правила гри «Бики та корови»:\n\n"
		"1. Комп'ютер загадує 4-значне число.\n"
		"2. Ваша мета - вгадати його.\n"
		"3. Після кожного введення програма повідомляє:\n"
		"   - «Бики»: цифра вгадана, але стоїть не на своєму місці.\n"
		"   - «Корови»: цифра вгадана і стоїть на своєму місці.\n"
		"4. Вводьте цифри без пробілів.\n\n"
		"Успіхів!";

	MessageBox::Show(rules, "Правила гри");
}
private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Ви дійсно бажаєте закінчити гру?", "Вихід",
		MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

		Application::Exit();
	}
}
};
}
