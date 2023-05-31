
#include <iostream>
#include <imgui.h>
#include <imgui-sfml.h>
#include <SFML/Graphics.hpp>
#pragma region SFMLFont
sf::Font font;

#pragma endregion
int main()
{if (!font.loadFromFile("Fonts\\arial.ttf"))
{
    std::cout << "Unable to load font!\n";
    return EXIT_FAILURE;
}
    sf::RenderWindow window1(sf::VideoMode(800, 600), L"Окно 1");
    sf::RenderWindow window2(sf::VideoMode(800, 600), L"Окно 2");
    //ImGui::SFML::Init(window1);
    // Загрузка шрифта для imgui
   // Load font
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->Clear();
    io.Fonts->AddFontFromFileTTF("Fonts\\impact.ttf", 20.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    // Update font texture
    ImGui::SFML::UpdateFontTexture();

    // Настройка стилей для imgui
    ImGui::StyleColorsDark();
    ImGui::GetStyle().WindowBorderSize = 0.f;
    ImGui::StyleColorsDark(); // устанавливаем стиль

    ImGuiStyle& style = ImGui::GetStyle(); // получаем текущий стиль
    while (window1.isOpen() && window2.isOpen())
    {
        
        sf::Event event;
        while (window1.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window1.close();
        }

        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        //ImGui::SFML::Update(window1, sf::seconds(1.f / 60.f));
        // Обновление и отрисовка содержимого окон
        window1.clear(sf::Color::White);
        // Рисуем содержимое окна 1
        window1.display();

        window2.clear(sf::Color::Black);
        // Рисуем содержимое окна 2
        window2.display();
    }

    return 0;
}
