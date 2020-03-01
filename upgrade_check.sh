# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    upgrade_check.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 17:05:03 by bleplat           #+#    #+#              #
#    Updated: 2020/03/01 17:17:35 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Update
git remote update > /dev/null

# Upgrade
if [ -z "$(git remote update | grep 'branch is behind')" ]; then
	printf "\e[35mUp to date.\e[0m\n"
else
	printf "\e[35mNew version available!\e[0m\n"
	read -p "\e[95mDo you want to upgrade now ? [y/N]\e[0m" answer
	if [ "$answer" = "y" ]; then
		printf "\e[35mUpgrading...\e[0m\n"
		git pull
	else
		printf "\e[35mNot upgrading...\e[0m\n"
	fi
fi

exit 0
