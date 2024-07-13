#include <dpp/dpp.h>
#include <iostream>
#include <string>
#include <map>
#include "token.h"
#include "command.h"
#include "embed.h"
#include "high_five.h"
#include "ping.h"
#include "heart.h"


const std::string BOT_TOKEN = Token;

std::map<std::string, command_definition> commands = {

	{ "ping", {"A ping command", handle_ping}},
	{ "embed", {"A test embed", handle_embed}},
	{ "heart", {
			"Heart a member", handle_heart, {
				
				{ dpp::command_option(dpp::co_mentionable, "mention", "help mention", true)}
		}
	}}

};

int main() {
	dpp::cluster bot(BOT_TOKEN);

	bot.on_log(dpp::utility::cout_logger());

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
	
	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
		dpp::command_interaction cmd_data = event.command.get_command_interaction();

		auto command_iter = commands.find(cmd_data.name);
		if (command_iter != commands.end()) {
			command_iter->second.function(bot, event);
		}



	});
	
	bot.on_user_context_menu([](const dpp::user_context_menu_t& event) {

		dpp::user user = event.get_user();
		dpp::user author = event.command.get_issuing_user();
		
		if (event.command.get_command_name() == "high five") {

			dpp::embed embed = dpp::embed()
				.set_color(dpp::colors::pink_cupcake)
				.set_description(author.get_mention() + " high fived " + user.get_mention() + "!")
				.set_image("https://i.imgur.com/VaynTWU.gif")
				.set_timestamp(time(0));

			dpp::message msg(event.command.channel_id, embed);
			event.reply(msg);
		}
		else if (event.command.get_command_name() == "kiss") {

			dpp::embed embed = dpp::embed()
				.set_color(dpp::colors::pink_cupcake)
				.set_description(author.get_mention() + " kissed " + user.get_mention() + "!")
				.set_image("https://i.imgur.com/cBbDGxZ.gif")
				.set_timestamp(time(0));

			dpp::message msg(event.command.channel_id, embed);
			event.reply(msg);
		}
		else if (event.command.get_command_name() == "slap") {
			dpp::embed embed = dpp::embed()
				.set_color(dpp::colors::pink_cupcake)
				.set_description(author.get_mention() + " slapped " + user.get_mention() + "!")
				.set_image("https://i.imgur.com/fpabdc9.gif")
				.set_timestamp(time(0));

			dpp::message msg(event.command.channel_id, embed);
			event.reply(msg);
		}
		});



	bot.on_ready([&bot](const dpp::ready_t& event) {
		if (dpp::run_once<struct register_bot_commands>()) {
			dpp::slashcommand command;
			command.set_name("high five")
				.set_application_id(bot.me.id)
				.set_type(dpp::ctxm_user);
			command.set_name("kiss")
				.set_application_id(bot.me.id)
				.set_type(dpp::ctxm_user);
			command.set_name("slap")
				.set_application_id(bot.me.id)
				.set_type(dpp::ctxm_user);

			
			bot.guild_command_create(command, 1035303033833259069);
		}

		});



	bot.start(false);
}