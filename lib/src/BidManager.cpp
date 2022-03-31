#include "BidManager.h"

#include <string>
#include <cassert>

BidManager::BidManager(Seat startSeat)
: startSeat(startSeat)
{}

Error BidManager::bid(BidVolume volume, Suit suit)
{
    return addBid(Bid(volume, suit));
}

Error BidManager::addBid(Bid bid)
{
    if (bid.isInvalid())
    {
        return WRONG_BID;
    }

    if (bid.volume() != PASS)
    {
        Bid previousNonPassBid = getPreviousRegularBid();
        if (bid.volume() < previousNonPassBid.volume())
        {
            return CANT_ADD_BID;
        }

        if (bid.volume() == previousNonPassBid.volume())
        {
            if (bid.suit() <= previousNonPassBid.suit())
            {
                return CANT_ADD_BID;
            }
        }
    }

    bids.push_back(bid);

    if (isPassRoundCompleted())
    {
        return CANT_ADD_BID;
    }

    return SUCCESS;
}

bool BidManager::isPassRoundCompleted()
{
    if (bids.size() < 4)
    {
        return false;
    }

    if (bids.rbegin()[0].volume() == PASS &&
        bids.rbegin()[1].volume() == PASS &&
        bids.rbegin()[2].volume() == PASS)
    {
        return true;
    }

    return false;
}

void BidManager::pass()
{
    Bid bid = Bid(PASS, CLUB);
    addBid(bid);
}

Error BidManager::contra()
{
    Bid bid = Bid(CONTRA, CLUB);
    addBid(bid);
    return SUCCESS;
}

Error BidManager::recontra()
{
    Bid bid = Bid(RECONTRA, CLUB);
    addBid(bid);
    return SUCCESS;
}

Bid BidManager::getBid(byte id)
{
    return bids[id];
}

Bid BidManager::getLastBid()
{
    if (bids.empty())
    {
        return Bid(NO_BID);
    }
    return bids.back();
}

Bid BidManager::getLastPartnerBid()
{
    if (bids.size() < 2)
    {
        return Bid(NO_BID);
    }
    return bids.rbegin()[1];
}

Bid BidManager::getMyLastBid()
{
    if (bids.size() < 4)
    {
        return Bid(NO_BID);
    }
    return bids.rbegin()[3];
}

Bid BidManager::getPreviousRegularBid()
{
    if (bids.size())
    {
        auto iter = bids.rbegin();
        while (iter != bids.rend())
        {
            if (iter->volume() != PASS)
                return *iter;
            iter++;
        };
    }

    return Bid(NO_BID, NO_TRUMP);
}

Bid BidManager::getFirstBid(Seat s)
{
    auto seatDiff = s - startSeat;
    if (seatDiff >= 0)
        return bids[seatDiff];
    else
        return bids[seatDiff + 4];
}

Bid BidManager::getSecondBid(Seat s)
{
    auto seatDiff = s - startSeat;
    if (seatDiff >= 0)
        return bids[seatDiff + 4];
    else
        return bids[seatDiff + 2 * 4];
}

Bid BidManager::getFirstBidOfCurrentSeat()
{
    return getFirstBid(getCurrentSeat());
}

Seat BidManager::getCurrentSeat()
{
    auto bidCounter = bids.size();

    return (Seat) ((bidCounter + startSeat) % 4);
}

Seat BidManager::getPartnerSeatOfCurrentSeat()
{
    auto currentSeat = getCurrentSeat();
    
    switch (currentSeat)
    {
        case SOUTH: return NORTH;
        case WEST:  return EAST;
        case NORTH: return SOUTH;
        case EAST:  return WEST;
        default:
            assert(false);
            return NORTH;
    }
}

std::string BidManager::printAllBids()
{
    std::string output = "\n\n                All bids    \n\n\n";
    output.append("\t\tS\t\tW\t\tN\t\tE  \n");
    output.append("-----------------------------------------\n");
    output.append(" \t\t");
    int currentSeat = startSeat;
    for (auto i = (int) SOUTH; i < currentSeat; ++i)
        output.append("\t\t-\t\t");

    for (const auto& bid : bids)
    {
        switch (bid.volume())
        {
            case RECONTRA:
                output.append("xx");
                break;
            case CONTRA:
                output.append("x");
                break;
            case PASS:
                output.append("-");
                break;
            default:
                output.append(std::to_string(bid.volume()));
                output.append(suit_s(bid.suit()));
        }

        bool isLastSeatInRow = currentSeat++ % 4 == (int) EAST;

        if (isLastSeatInRow)
            output.append(" \n");

        if ((bid.volume() != PASS && bid.suit() == NO_TRUMP) && !isLastSeatInRow)
            output.append(" \t");
        else
            output.append(" \t\t");
    }

    output.append(" \n");
    
    return output;
}

Bid BidManager::veryNextBid()
{
    auto lastBid = getLastBid();

    if (lastBid.volume() == NO_BID)
    {
        return Bid(ONE_B, CLUB);
    }

    Suit suit = CLUB;
    BidVolume volume = lastBid.volume();

    switch (lastBid.suit())
    {
        case CLUB:
            suit = DIAMOND;
            break;
        case DIAMOND:
            suit = HEART;
            break;
        case HEART:
            suit = SPADE;
            break;
        case SPADE:
            suit = NO_TRUMP;
            break;
        case NO_TRUMP:
            suit = CLUB;
            volume = static_cast<BidVolume>((static_cast<int>(lastBid.volume()) + 1));
            break;
        default:
            suit = CLUB;
            volume = CONTRA;
    }

    return Bid(volume,suit);
}
