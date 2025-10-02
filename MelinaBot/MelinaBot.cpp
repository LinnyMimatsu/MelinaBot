#include <dpp/dpp.h>
#include <iostream>
#include <string>
#include <map>
#include "Token.h"
#include "command.h"
#include "embed.h"
#include "high_five.h"
#include "kiss.h"
#include "slap.h"
#include "ping.h"
#include "heart.h"
#include "gif_randomizer.h"

/*grabs the bot token from token.h*/
const std::string BOT_TOKEN = Token;

/*utilizing maps to hold the mentioning data for mentions*/
std::map<std::string, command_definition> commands = {

	{ "ping", {"A ping command", handle_ping}},
	{ "embed", {"A test embed", handle_embed}},
	{ "heart", {
			"heart a member", handle_heart, {

				{ dpp::command_option(dpp::co_mentionable, "mention", "mention a user", true)}
		}
	}},
	{ "highfive", {

			"high five a member", handle_high_five, {

				{ dpp::command_option(dpp::co_mentionable, "mention", "mention a user", true)}

			}
		}},
	{ "kiss", {

			"kiss a member", handle_kiss, {

				{ dpp::command_option(dpp::co_mentionable, "mention", "mention a user", true)}

			}
		}},
	{ "slap", {

			"slap a member", handle_slap, {

				{ dpp::command_option(dpp::co_mentionable, "mention", "mention a user", true)}

			}
		}}
};


int main() {

	
	
	/*setting up dpp class*/
	dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);

	bot.on_log(dpp::utility::cout_logger());

	bot.on_ready([&bot](const dpp::ready_t& event) {

		bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_game, "with Lin!"));

		});

	/*creating the slash commands*/
	bot.on_ready([&](const dpp::ready_t& event) {
		if (dpp::run_once<struct bulk_register>()) {
			std::vector<dpp::slashcommand> slash_commands;
			for (auto& def : commands) {
				dpp::slashcommand c;
				c.set_name(def.first).
					set_description(def.second.description).
					set_application_id(bot.me.id);
				c.options = def.second.paramters;
				slash_commands.push_back(c);
			}
			bot.global_bulk_command_create(slash_commands);
		}
	});
	
	/*running the slash commands*/
	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
		dpp::command_interaction cmd_data = event.command.get_command_interaction();

		auto command_iter = commands.find(cmd_data.name);
		if (command_iter != commands.end()) {
			command_iter->second.function(bot, event);
		}
	});

	/*initialize*/
	bot.start(dpp::st_wait);
}