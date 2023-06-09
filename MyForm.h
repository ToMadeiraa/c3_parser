#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <regex>
#include <string>
#include <vector>

std::string clear_names(std::string input_strr) {
	std::string result = "";
	for (auto x : input_strr) {
		if ((static_cast<int>(x) >= 33 && static_cast<int>(x) <= 126) && x != '*') {
			result.push_back(x);
		}
	}
	return result;
}

std::string clear_ids(std::string input_strrr) {
	std::string result = "";
	for (auto x : input_strrr) {
		if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9') {
			result.push_back(x);
		}
	}
	return result;
}


namespace csxasd {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
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
	private: System::Windows::Forms::Button^ BTNShowFilesDialog;

	protected:

	protected:

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
			this->BTNShowFilesDialog = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// BTNShowFilesDialog
			// 
			this->BTNShowFilesDialog->Location = System::Drawing::Point(112, 282);
			this->BTNShowFilesDialog->Name = L"BTNShowFilesDialog";
			this->BTNShowFilesDialog->Size = System::Drawing::Size(400, 59);
			this->BTNShowFilesDialog->TabIndex = 0;
			this->BTNShowFilesDialog->Text = L"ќткрыть реплей";
			this->BTNShowFilesDialog->UseVisualStyleBackColor = true;
			this->BTNShowFilesDialog->Click += gcnew System::EventHandler(this, &MyForm::BTNShowFilesDialog_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 353);
			this->Controls->Add(this->BTNShowFilesDialog);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BTNShowFilesDialog_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Stream^ Mystream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "rep files (*.rep)|*.rep|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		int a = 0;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ str1; //весь файл
			String^ str2; //6000 от GameMapSnapShotEnd
			int start;

			int maskpath;
			String^ maskpath_str;

			if ((Mystream = openFileDialog1->OpenFile()) != nullptr) {

				str1 = System::IO::File::ReadAllText(openFileDialog1->FileName);

				start = str1->IndexOf("GameMapSnapShotEnd");
				str2 = str1->Substring(start, 6000);
				std::string str_all = "";
				for (int i = 0; i < 6000; i++) {
					str_all.push_back(str2[i]);
				}
				//настройки комнаты
				// 
				// 
				std::cout << std::endl;
				std::cout << "Room settings:";
				std::cout << std::endl;
				std::cout << std::endl;
				//шаблон карты
				std::smatch m;
				std::regex regexp1("terrain[a-zA-Z0-9]+.[a-zA-Z0-9]+.[a-zA-Z0-9]+");
				std::regex_search(str_all, m, regexp1);
				std::string terrainmask = m.str();
				{
					std::cout << "terrainmask: " << terrainmask << std::endl;
				}
				
				//размер карты
				std::regex regexp2("mapsize....(.)");
				std::regex_search(str_all, m, regexp2);
				std::string mapsize = m.str(1);
				{
					std::cout << "mapsize: " << mapsize << std::endl;
				}

				//тип карты
				std::regex regexp3("terraintype....(.)");
				std::regex_search(str_all, m, regexp3);
				std::string terraintype = m.str(1);

				{
					std::cout << "terraintype: " << terraintype << std::endl;
				}

				//тип рельефа
				std::regex regexp4("relieftype....(.)");
				std::regex_search(str_all, m, regexp4);
				std::string relieftype = m.str(1);
				{
					std::cout << "relieftype: " << relieftype << std::endl;
				}

				//начальные ресурсы
				std::regex regexp5("resourcestart....(.)");
				std::regex_search(str_all, m, regexp5);
				std::string resourcestart = m.str(1);
				{
					std::cout << "resourcestart: " << resourcestart << std::endl;
				}

				//ресурсы
				std::regex regexp6("resourcemines....(.)");
				std::regex_search(str_all, m, regexp6);
				std::string resourcemines = m.str(1);
				{
					std::cout << "resourcemines: " << resourcemines << std::endl;
				}

				//сезон 
				std::regex regexp7("season....(.)");
				std::regex_search(str_all, m, regexp7);
				std::string season = m.str(1);
				{
					std::cout << "season: " << season << std::endl;
				}

				//стартовые опции
				std::regex regexp8("activeoption....(.)");
				std::regex_search(str_all, m, regexp8);
				std::string activeoption = m.str(1);
				{
					std::cout << "activeoption: " << activeoption << std::endl;
				}

				//количество юнитов
				std::regex regexp9("startingunits....(.)");
				std::regex_search(str_all, m, regexp9);
				std::string startingunits = m.str(1);
				{
					std::cout << "startingunits: " << startingunits << std::endl;
				}

				//шар
				std::regex regexp10("balloon....(.)");
				std::regex_search(str_all, m, regexp10);
				std::string balloon = m.str(1);
				{
					std::cout << "balloon: " << balloon << std::endl;
				}

				//пушки
				std::regex regexp11("cannons....(.)");
				std::regex_search(str_all, m, regexp11);
				std::string cannons = m.str(1);
				{
					std::cout << "cannons: " << cannons << std::endl;
				}

				//врем€ мира
				std::regex regexp13("peacetime....(..)");
				std::regex_search(str_all, m, regexp13);
				std::string peacetime = m.str(1);
				{
					std::cout << "peacetime: " << peacetime << std::endl;
				}

				//18век
				std::regex regexp14("century18....(.)");
				std::regex_search(str_all, m, regexp14);
				std::string century18 = m.str(1);
				{
					std::cout << "century18: " << century18 << std::endl;
				}

				//опции захвата
				std::regex regexp15("capture....(.)");
				std::regex_search(str_all, m, regexp15);
				std::string capture = m.str(1);
				{
					std::cout << "capture: " << capture << std::endl;
				}

				//опции дипа и маркета
				std::regex regexp16("marketdip....(.)");
				std::regex_search(str_all, m, regexp16);
				std::string marketdip = m.str(1);
				{
					std::cout << "marketdip: " << marketdip << std::endl;
				}

				//союзники р€дом?
				std::regex regexp17("teams....(.)");
				std::regex_search(str_all, m, regexp17);
				std::string teams = m.str(1);
				{
					std::cout << "teams: " << teams << std::endl;
				}

				//лимит
				std::regex regexp18("limit....(.)");
				std::regex_search(str_all, m, regexp18);
				std::string limit = m.str(1);
				{
					std::cout << "limit: " << limit << std::endl;
				}

				//скорость игры
				std::regex regexp19("gamespeed....(.)");
				std::regex_search(str_all, m, regexp19);
				std::string gamespeed = m.str(1);
				{
					std::cout << "gamespeed: " << gamespeed << std::endl;
				}

				//внутриигровой помощник
				std::regex regexp20("adviserassistant....(.)");
				std::regex_search(str_all, m, regexp20);
				std::string adviserassistant = m.str(1);
				{
					std::cout << "adviserassistant: " << adviserassistant << std::endl;
				}

				//скип 1000 символов

				std::string str_all_after_settings;
				str_all_after_settings.resize(5010);
				for (int i = 1000; i < 6000; i++) {
					str_all_after_settings[i - 1000] = str_all[i];
				}

				int k = 0;
				std::vector<std::string> strings;
				for (int i = 0; i <= 11; i++) {
					std::string temp = "";
					while (str_all_after_settings[k] != '*')  {
						temp.push_back(str_all_after_settings[k]);
						k++;
					}
					k += 5;
					strings.push_back(temp);
				}

				std::regex regeexp_name("name....(.{5,24})team");
				std::regex regeexp_team("team....(..)");
				std::regex regeexp_color("color....(..)");
				std::regex regeexp_lanid("lanid....([0-9]+)");

				std::vector<std::string> names_vec;
				std::vector<std::string> teams_vec;
				std::vector<std::string> colors_vec;
				std::vector<std::string> lanids_vec;

				std::cout << std::endl;
				std::cout << "Players info:";
				std::cout << std::endl;

				for (int i = 0; i < 11; i++) {
					std::regex_search(strings[i], m, regeexp_name);
					names_vec.push_back(clear_names(m.str(1)));
					std::regex_search(strings[i], m, regeexp_team);
					teams_vec.push_back(clear_ids(m.str(1)));
					std::regex_search(strings[i], m, regeexp_color);
					colors_vec.push_back(clear_ids(m.str(1)));
					std::regex_search(strings[i], m, regeexp_lanid);
					lanids_vec.push_back(clear_ids(m.str(1)));
					
					std::cout << "Player " << i+1 << ": " << names_vec[i] << "\t" "|  team: " << teams_vec[i] << "\t" << "|  color: " << colors_vec[i] << "\t" << "| lan id: " << lanids_vec[i] << "\t" << std::endl;
				}

				String^ str2_steam;
				int start_steam;
				start_steam = str1->IndexOf("playersinfo");
				str2_steam = str1->Substring(start_steam+20, 2500);
				std::string str_steam;
				for (int i = 0; i < 2500; i++) {
					str_steam.push_back(str2_steam[i]);
				}
				std::vector<std::string> strings_steam;

				int j = 0;
				for (int i = 0; i <= 11; i++) {
					std::string temp = "";
					while (str_steam[j] != '*') {
						temp.push_back(str_steam[j]);
						j++;
					}
					temp.push_back('*');
					j += 5;
					strings_steam.push_back(temp);
				}

				/*for (auto i : strings_steam) {
					std::cout << i << std::endl;
				}
				std::cout << "SIZE OF strings_steam IS " << strings_steam.size();*/

				std::regex regeexp_sic("si....(.+)si1");
				std::regex regeexp_si1("si1...(.+)si2");
				std::regex regeexp_si2("si2...(.+)si3");
				std::regex regeexp_si3("si3...(.+)snc");

				std::regex regeexp_snc("sn....(.+)sn1");
				std::regex regeexp_sn1("sn1...(.+)sn2");
				std::regex regeexp_sn2("sn2...(.+)sn3");
				std::regex regeexp_sn3("sn3...(.+)*");

				std::vector<std::string> sic_vec;
				std::vector<std::string> si1_vec;
				std::vector<std::string> si2_vec;
				std::vector<std::string> si3_vec;
				std::vector<std::string> snc_vec;
				std::vector<std::string> sn1_vec;						
				std::vector<std::string> sn2_vec;
				std::vector<std::string> sn3_vec;

				std::cout << std::endl;
				std::cout << "Steam info:" << std::endl << std::endl;

				for (int i = 0; i <= 11; i++) {
					std::regex_search(strings_steam[i], m, regeexp_sic);
					sic_vec.push_back(clear_ids(m.str(1)));
					std::regex_search(strings_steam[i], m, regeexp_si1);
					si1_vec.push_back(clear_ids(m.str(1)));
					std::regex_search(strings_steam[i], m, regeexp_si2);
					si2_vec.push_back(clear_ids(m.str(1)));
					std::regex_search(strings_steam[i], m, regeexp_si3);
					si3_vec.push_back(clear_ids(m.str(1)));
					std::regex_search(strings_steam[i], m, regeexp_snc);
					snc_vec.push_back(clear_names(m.str(1)));
					std::regex_search(strings_steam[i], m, regeexp_sn1);
					sn1_vec.push_back(clear_names(m.str(1)));
					std::regex_search(strings_steam[i], m, regeexp_sn2);
					sn2_vec.push_back(clear_names(m.str(1)));
					std::regex_search(strings_steam[i], m, regeexp_sn3);
					sn3_vec.push_back(clear_names(m.str(1)));
					if (i!=0) {
					std::cout << "Player " << i << std::endl;
					std::cout << "Current steam id: " << sic_vec[i] << "\t" << "| Steam id #1: " << si1_vec[i] << "\t" << "| Steam id #2: " << si2_vec[i] << "\t" << "| Steam id #3: " << si3_vec[i] << std::endl;
					std::cout << "Current steam nickname: " << snc_vec[i] << "\t" << "| Steam nickname #1: " << sn1_vec[i] << "\t" << "| Steam nickname #2: " << sn2_vec[i] << "\t" << "| Steam nickname #3: " << sn3_vec[i];
					std::cout << std::endl << std::endl << std::endl;
					}
				}


				Mystream->Close();
			}
		}
	}
};
}
