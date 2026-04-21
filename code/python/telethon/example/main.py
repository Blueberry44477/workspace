from telethon import TelegramClient
from telethon.errors import FloodWaitError, PeerFloodError
import random
import socks
import asyncio
import os

API_ID = os.environ.get("API_ID")
API_HASH = os.environ.get("API_HASH")
GROUP_LINK = os.environ.get("GROUP_LINK")

if not API_ID or not API_HASH:
    raise ValueError("Environment variables API_ID or API_HASH are not set.")

# TEXT_MESSAGE = "Unusual login detected. Verify your identity here: http://secure-telegram-verify.com/login"
TEXT_MESSAGE = "New Message"

proxy = {
    'proxy_type': socks.SOCKS5,
    'addr': 'proxy_address',
    'port': 1080,
    'username': 'user',
    'password': 'pass',
    'rdns': True
}

async def main():
    async with TelegramClient("session", API_ID, API_HASH, proxy=None) as client:
        try:
            await client.start()

            group_entity = await client.get_entity(GROUP_LINK)
            participants = await client.get_participants(group_entity)
            # participants = [6988558970, 5346546566]


            print(f"{len(participants)} users in the group.")

            for participant in participants:
                if getattr(participant, 'bot', False) or getattr(participant, 'deleted', False):
                        continue
                try:
                    await client.send_message(participant, TEXT_MESSAGE)
                    print(f"Sent a message to {participant.first_name} {participant.last_name}")

                    sleep_time = random.randint(1,2)
                    print(f"Waiting {sleep_time} seconds before next message.")
                    await asyncio.sleep(sleep_time)

                except FloodWaitError as e:
                        print(f"[LIMIT] Telegram forced wait: {e.seconds} seconds.")
                        await asyncio.sleep(e.seconds)
                except Exception as ex:
                    print(f"{ex}")
        except Exception as e:
                print(f"{e}")

if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("Interrupted.")