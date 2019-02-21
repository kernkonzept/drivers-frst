/*
 * (c) 2009-2012 Adam Lackorzynski <adam@os.inf.tu-dresden.de>
 *     economic rights: Technische Universität Dresden (Germany)
 *
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#ifndef L4_DRIVERS_UART_S3C2410_H__
#define L4_DRIVERS_UART_S3C2410_H__

#include "uart_base.h"

namespace L4
{
  class Uart_s3c : public Uart
  {
  protected:
    enum Uart_type
    {
      Type_24xx, Type_64xx, Type_s5pv210,
    };

    Uart_type type() const { return _type; }

  public:
    explicit Uart_s3c(Uart_type type) : _type(type) {}
    bool startup(Io_register_block const *) override;
    void shutdown() override;
    bool change_mode(Transfer_mode m, Baud_rate r) override;
    int get_char(bool blocking = true) const override;
    int char_avail() const override;
    inline void out_char(char c) const;
    int write(char const *s, unsigned long count) const override;
    void fifo_reset();

  protected:
    virtual void ack_rx_irq() const = 0;
    virtual void wait_for_empty_tx_fifo() const = 0;
    virtual void wait_for_non_full_tx_fifo() const = 0;
    virtual unsigned is_rx_fifo_non_empty() const = 0;

  private:
    Uart_type _type;
  };

  class Uart_s3c2410 : public Uart_s3c
  {
  public:
    Uart_s3c2410() : Uart_s3c(Type_24xx) {}

  protected:
    void ack_rx_irq() const override {}
    void wait_for_empty_tx_fifo() const override;
    void wait_for_non_full_tx_fifo() const override;
    unsigned is_rx_fifo_non_empty() const override;

    void auto_flow_control(bool on);
  };

  class Uart_s3c64xx : public Uart_s3c
  {
  public:
    Uart_s3c64xx() : Uart_s3c(Type_64xx) {}

  protected:
    void ack_rx_irq() const override;
    void wait_for_empty_tx_fifo() const override;
    void wait_for_non_full_tx_fifo() const override;
    unsigned is_rx_fifo_non_empty() const override;
  };

  class Uart_s5pv210 : public Uart_s3c
  {
  public:
    Uart_s5pv210() : Uart_s3c(Type_s5pv210) {}

  protected:
    void ack_rx_irq() const override;
    void wait_for_empty_tx_fifo() const override;
    void wait_for_non_full_tx_fifo() const override;
    unsigned is_rx_fifo_non_empty() const override;
  };
};

#endif
