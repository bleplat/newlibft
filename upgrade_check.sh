# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    upgrade_check.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 17:05:03 by bleplat           #+#    #+#              #
#    Updated: 2020/03/01 17:31:40 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Update
printf "\e[35m"
git remote update 1> /dev/null

# Upgrade
if [ -z "$(git status | grep 'branch is behind')" ]; then
	printf "\e[35mUp to date.\e[0m\n"
else
	printf "\n"
	printf "\e[95m     / \\                                      / \\   \e[0m\n"
	printf "\e[95m    / | \\    \e[35mNEW VERSION AVAILABLE!    / | \\  \e[0m\n"
	printf "\e[95m   /  .  \\                                  /  .  \\ \e[0m\n"
	printf "\n"
	read -p "Do you want to upgrade now? [y/N]" answer
	if [ "$answer" = "y" ]; then
		printf "\e[35mUpgrading...\e[0m\n"
		git pull
		printf "\e[35mDone.\e[0m\n"
	else
		printf "\e[35mNot upgrading...\e[0m\n"
	fi
fi

exit 0
