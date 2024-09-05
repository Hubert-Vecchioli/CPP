/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:50:36 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 08:37:43 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define NB_IDEAS 100

class Brain
{
	private:
		std::string	ideas_[NB_IDEAS];
	public:
		Brain(void);
		Brain(Brain const &src);
		virtual ~Brain(void);
		Brain & operator=(Brain const &rhs);

		const std::string *getIdeas(void) const;
		void setIdea(int index, std::string idea);
		void setIdeas(const std::string *ideas);
};

#endif