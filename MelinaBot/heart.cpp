#include <iostream>
#include <command.h>
#include <heart.h>


void handle_heart(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	
	/*reads the guild user's ID to check perms*/
	dpp::permission perms = event.command.get_resolved_permission(event.command.usr.id);

	/*checks if guild user's ID has matching perms*/
	if (perms.can(dpp::p_administrator)) {

		/*grabbing co_mentionable user and converting their ID to a mention*/
		dpp::snowflake userTarget = std::get<dpp::snowflake>(event.get_parameter("mention"));
		std::string userTargetReal = "<@" + userTarget.str() + ">";
		/*grabbing command author*/
		dpp::user author = event.command.get_issuing_user();

		/*creating embed*/
		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::pink_cupcake)
			.set_description(author.get_mention() + " hearted " + userTargetReal + "! :heart:");
		dpp::message msg(event.command.channel_id, embed);

		/*returns a reply to Discord*/
		event.reply(msg);
	
	} else {

		/*if they have insufficient perms, return "you can't use this command"*/
		dpp::embed embed = dpp::embed()
			.set_color(dpp::colors::pink_cupcake)
			.set_description("You can't use that command!");

		dpp::message msg(event.command.channel_id, embed);
		event.reply(msg);
	}

	
}